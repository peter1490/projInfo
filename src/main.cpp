#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <SOIL/SOIL.h>

#include "../include/Camera.h"
#include "../include/Map.h"

#include "../include/Robot.h"
#include "../include/Road.h"
#include "../include/Wall.h"
#include "../include/Cube.h"

// Objet Camera
Camera *cam = new Camera();
// Objet Scène
Map *m = new Map();

Robot *robotInstance = new Robot();
//Wall *wallInstance = new Wall();
Road *roadInstance = new Road();
Map *mapInstance = new Map();

//House *houseInstance = new House();

double angleXRobot = 0;
double angleZRobot = 0;

double bullet = -5;
double sunAngle = 0;
bool left = true;
bool right = false;
bool up = false;
bool down = false;
int pass = 0;
float langue = 0.2;

/** GESTION FENETRE **/
void reshapeWindow(int w, int h)
{
    if (h == 0)
        h = 1;

    float ratio =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 348.0f);
    glMatrixMode(GL_MODELVIEW);
}

/** FONCTIONS DE GESTION CLAVIER **/
void KeyboardDown(unsigned char key, int xx, int yy)
{
    switch(key)
    {
        case 'e': // Unlock Camera
            cam->locked = (cam->locked)?0:1;
            break;
        case 'z':
            robotInstance->rFoward = 1;
            break;
        case 's':
            robotInstance->rBack = 1;
            break;
        case 'l':
            cam->deltaStrafe = -10;
            break;
        case 'q':
            robotInstance->rLeft = 1;
            break;
        case 'd':
            robotInstance->rRight = 1;
            break;
        case 'u':
            bullet -= 0.05;
            break;
    }
}

void KeyboardUp(unsigned char key, int xx, int yy)
{
    switch(key)
    {
        case 'z':
        case 's':
            cam->deltaForward = 0;
            break;
        case 'q':
        case 'd':
            cam->deltaStrafe = 0;
            break;
        case 'u':
            bullet -= 0.05;
            break;
    }
}

void SpecialDown(int key, int xx, int yy)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            cam->deltaForward = 1;
            break;
        case GLUT_KEY_DOWN:
            cam->deltaForward = -1;
            break;
        case GLUT_KEY_RIGHT:
            cam->deltaStrafe = -1;
            break;
        case GLUT_KEY_LEFT:
            cam->deltaStrafe = 1;
            break;
    }
}

void SpecialUp(int key, int xx, int yy)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
            cam->deltaForward = 0;
            break;
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_LEFT:
            cam->deltaStrafe = 0;
            break;
    }
}

/** FONCTIONS DE GESTION SOURIS (ORIENTATION CAMERA) **/
void mouseMove(int x, int y)
{
    // Rentres uniquement lors du clic
    cam->orienterCam(x, y);
}
void mouseButton(int button, int state, int x, int y)
{
    // Gestion camera en fonction du clic souris
    if (button == GLUT_LEFT_BUTTON)
    {
        // Relacher la camera
        if (state == GLUT_UP)
        {
            cam->releaseCam();
        }
            // Mise à jour origine du clic
        else
        {
            cam->grabCam(x, y);
        }
    }
}

/** GESTION DEPLACEMENT CAMERA **/
void computePos(int inutile)
{
    cam->updatePos();
    glutTimerFunc(10, computePos, 0);
}

/** AFFICHAGE **/
void renderScene(void)
{
    double speed = 0.02;
    int maxHeight = 40;
    int maxWidth = 40;

    if(angleXRobot >= -maxWidth && left)
        angleXRobot -= speed;

    if(angleXRobot <= maxWidth && right)
        angleXRobot += speed;

    if(angleZRobot >= -maxHeight && up)
        angleZRobot -= speed;

    if(angleZRobot <= maxHeight && down)
        angleZRobot += speed;

    if((angleXRobot < -maxWidth || angleXRobot > maxWidth || (fabs(angleXRobot) > - (pow(5,-7)) && fabs(angleXRobot) < pow(10,-7)))
        && fabs(angleZRobot) > - (pow(10,-7)) && fabs(angleZRobot) < pow(10,-7))
    {
        if(pass == 0)
        {
            up = true;
            down = false;
            left = false;
            right = false;
        }
        else if(pass == 2)
        {
            up = false;
            down = false;
            if(angleXRobot < -maxWidth)
            {
                right = true;
            }
            else if(angleXRobot > maxWidth)
            {
                left = true;
            }
            else
            {
                left = rand() % 2 == 0;
                right = !left;
            }
            pass = -1;
        }
            pass ++;
    }

    if(angleZRobot < -40)
    {
        up = false;
        down = true;
    }

    if(angleZRobot > 40)
    {
        up = true;
        down = false;
    }

    int angle = 0;
    if(left)
        angle = -90;

    if(right)
        angle = -270;

    if(up)
        angle = -180;

    if(down)
        angle = 0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Définition de la caméra
    gluLookAt(  cam->posx, cam->posy, cam->posz,
                cam->posx+cam->dirx, cam->posy+cam->diry,  cam->posz+cam->dirz,
                0.0f, 1.0f,  0.0f
    );

    sunAngle += 0.1;

    if(sunAngle >= 360)
        sunAngle = -360;

    //puts("ok");
    mapInstance->DrawSun(sunAngle);
    mapInstance->DrawTree();
    mapInstance->DrawPortal1();
    mapInstance->DrawPortal2();
    robotInstance->display(bullet);
    //wallInstance->draw();
    m->DrawGround();
    m->DrawSkybox(cam);

    glutSwapBuffers();

}

void LoadTextures()
{
    m->LoadTextures();
}

int main(int argc, char **argv)
{
    /** CREATION FENETRE **/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Robot");

    /** FONCTIONS GLUT **/
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
    glutIdleFunc(renderScene);
    glutTimerFunc(10, computePos, 0);

    /** GESTION CLAVIER **/
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(KeyboardDown);
    glutKeyboardUpFunc(KeyboardUp);
    glutSpecialFunc(SpecialDown);
    glutSpecialUpFunc(SpecialUp);

    /** GESTION SOURIS **/
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    /** INIT TEXTURES **/
    LoadTextures();

    /** INIT GL STATES **/
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutMainLoop();

    return (1);
}


