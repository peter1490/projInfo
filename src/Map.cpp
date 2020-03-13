#include "../include/Map.h"
#include "../include/Block.h"
#include "../include/Wall.h"

#define GL_CLAMP_TO_EDGE 0x812F
#define SKY_DISTANCE 200.0f

GLfloat Map::lightColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat Map::lightPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};

Map::Map()
{
    this->sunTexture = 0;
}

void Map::LoadTextures()
{
    // Skybox
    Skybox[0] = SOIL_load_OGL_texture("img/skybox1.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    Skybox[1] = SOIL_load_OGL_texture("img/skybox2.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    Skybox[2] = SOIL_load_OGL_texture("img/skybox3.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    Skybox[3] = SOIL_load_OGL_texture("img/skybox4.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    Skybox[4] = SOIL_load_OGL_texture("img/skybox5.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    Skybox[5] = SOIL_load_OGL_texture("img/skybox6.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    // Textures utilisables
    ListeTextures[0] = SOIL_load_OGL_texture("img/cliff.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[1] = SOIL_load_OGL_texture("img/cobble.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[2] = SOIL_load_OGL_texture("img/darkgrass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[3] = SOIL_load_OGL_texture("img/darkwoodplanks.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[4] = SOIL_load_OGL_texture("img/darkwoodtiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[5] = SOIL_load_OGL_texture("img/deadgrass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[6] = SOIL_load_OGL_texture("img/floorbrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[7] = SOIL_load_OGL_texture("img/graybrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[8] = SOIL_load_OGL_texture("img/graybricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[9] = SOIL_load_OGL_texture("img/greybrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[10] = SOIL_load_OGL_texture("img/greybricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[11] = SOIL_load_OGL_texture("img/lightgrass.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[12] = SOIL_load_OGL_texture("img/lightwoodplanks.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[13] = SOIL_load_OGL_texture("img/lightwoodtiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[14] = SOIL_load_OGL_texture("img/mossbricktiles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[15] = SOIL_load_OGL_texture("img/pavement.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[16] = SOIL_load_OGL_texture("img/pebbles.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[17] = SOIL_load_OGL_texture("img/redbrick.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[18] = SOIL_load_OGL_texture("img/metalgate.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    //ListeTextures[19] = SOIL_load_OGL_texture("img/betonurban.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    ListeTextures[19] = SOIL_load_OGL_texture("img/terre.jpg",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
}

void Map::DrawGround()
{
    Block *b = new Block(5.0f, 5.0f, 0.2f);
    Block *b2 = new Block(5.0f, 5.0f, 0.2f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, ListeTextures[11]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 0.0f, -50.0f);
    glTexCoord2f(0.0f, 50.0f);
    glVertex3f(-50.0f, 0.0f,  50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(50.0f, 0.0f, 50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, -50.0f);
    glEnd();
    glTranslatef(0.0f, 1.0f, 0.0f);

    glPushMatrix();
        glTranslatef(-10, -1, 0);
        glRotatef(90, 0, 1, 0);
        b->SetTexture(FRONT, ListeTextures[7]);
        b->SetTexture(BACK, ListeTextures[7]);
        b->SetTexture(TOP, ListeTextures[7]);
        b->SetTexture(BOT, ListeTextures[7]);
        b->SetTexture(RIGHT, ListeTextures[7]);
        b->SetTexture(LEFT, ListeTextures[7]);
        b->SetTexture(SPHERE, ListeTextures[7]);
        b->Draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2, -1, 10);
        b2->SetTexture(FRONT, ListeTextures[7]);
        b2->SetTexture(BACK, ListeTextures[7]);
        b2->SetTexture(TOP, ListeTextures[7]);
        b2->SetTexture(BOT, ListeTextures[7]);
        b2->SetTexture(RIGHT, ListeTextures[7]);
        b2->SetTexture(LEFT, ListeTextures[7]);
        b2->SetTexture(SPHERE, ListeTextures[7]);
        b2->Draw();
    glPopMatrix();


}

void Map::DrawSun(double sunAngle)
{

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,ListeTextures[11]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

        GLUquadric* params2 = gluNewQuadric();
        gluQuadricTexture(params2,GL_TRUE);
        glPushMatrix();
        glRotatef(sunAngle, 0, 0, 1);
        glTranslatef(200, 55, 0);
        glDisable(GL_LIGHTING);
        gluSphere(params2, 10, 100, 100);
        glutSolidSphere(21,100,100);

        glLightfv(GL_LIGHT2, GL_DIFFUSE, this->lightColor);
        glLightfv(GL_LIGHT2, GL_POSITION, this->lightPos);
        glPopMatrix();
    glPopMatrix();

}

void Map::DrawPortal1()
{
    glPushMatrix();
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT2);

        glPushMatrix();
            glTranslatef(-9.8, 2, -2.5);
            glRotatef(90,0,1,0);
            glColor3f(0.0f, 1.0f, 0.0f);
            glutSolidCone(1.5,0,20,30);
        glPopMatrix();
    glPopMatrix();

}

void Map::DrawPortal2()
{
    glPushMatrix();
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT2);

        glPushMatrix();
            glTranslatef(0.5, 2, 10);
            glRotatef(90,0,0,1);
            glColor3f(0.0f, 1.0f, 0.0f);
            glutSolidCone(1.5,0,20,30);
        glPopMatrix();
    glPopMatrix();

}

void Map::DrawTree()
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT2);
glPushMatrix();
//____________ Tronc ______________

    glPushMatrix();
        glTranslatef(4.81, 1.425, 0);
        glPushMatrix();
            glColor3f(0.9f, 0.5f, 0.1f);
            glScalef(0.7, 5, 0.7);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//__________________________________

//___________ Feuilles ______________

    glPushMatrix();
        glTranslatef(4.81, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(3, 2.5, 3);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.1, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(-6, 0, -1);
//____________ Tronc ______________

    glPushMatrix();
        glTranslatef(4.81, 1.425, 0);
        glPushMatrix();
            glColor3f(0.9f, 0.5f, 0.1f);
            glScalef(0.7, 5, 0.7);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//__________________________________

//___________ Feuilles ______________

    glPushMatrix();
        glTranslatef(4.81, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(3, 2.5, 3);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.1, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(-2, 0, -3);
//____________ Tronc ______________

    glPushMatrix();
        glTranslatef(4.81, 1.425, 0);
        glPushMatrix();
            glColor3f(0.9f, 0.5f, 0.1f);
            glScalef(0.7, 5, 0.7);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//__________________________________

//___________ Feuilles ______________

    glPushMatrix();
        glTranslatef(4.81, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(3, 2.5, 3);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.1, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(1.5, 0, 5);
//____________ Tronc ______________

    glPushMatrix();
        glTranslatef(4.81, 1.425, 0);
        glPushMatrix();
            glColor3f(0.9f, 0.5f, 0.1f);
            glScalef(0.7, 5, 0.7);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//__________________________________

//___________ Feuilles ______________

    glPushMatrix();
        glTranslatef(4.81, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(3, 2.5, 3);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.1, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();

glPushMatrix();
glTranslatef(-2, 0, -3);
//____________ Tronc ______________

    glPushMatrix();
        glTranslatef(4.81, 1.425, 0);
        glPushMatrix();
            glColor3f(0.9f, 0.5f, 0.1f);
            glScalef(0.7, 5, 0.7);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//__________________________________

//___________ Feuilles ______________

    glPushMatrix();
        glTranslatef(4.81, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(3, 2.5, 3);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.1, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.5, 2.425, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.5f, 0.0f);
            glScalef(2.5, 1.5, 2.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

glPopMatrix();
}

void Map::DrawSkybox(Camera *cam)
{
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    // Face
    glBindTexture(GL_TEXTURE_2D, Skybox[1]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(0, 1);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glEnd();

    // Render the left quad
    glBindTexture(GL_TEXTURE_2D, Skybox[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(0, 1);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glEnd();

    // Render the back quad
    glBindTexture(GL_TEXTURE_2D, Skybox[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f( SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(0, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);

    glEnd();

    // Render the right quad
    glBindTexture(GL_TEXTURE_2D, Skybox[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(0, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glEnd();

    // Render the top quad
    glBindTexture(GL_TEXTURE_2D, Skybox[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glVertex3f(-SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f( SKY_DISTANCE + cam->posx, SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glEnd();

    // Render the bottom quad

    glBindTexture(GL_TEXTURE_2D, Skybox[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glTexCoord2f(0, 0);
    glVertex3f(-SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 0);
    glVertex3f(SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, -SKY_DISTANCE + cam->posz);
    glTexCoord2f(1, 1);
    glVertex3f(SKY_DISTANCE + cam->posx, -SKY_DISTANCE + cam->posy, SKY_DISTANCE + cam->posz);
    glEnd();
}
