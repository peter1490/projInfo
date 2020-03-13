#include "../include/Robot.h"

Robot::Robot(){
    this->langue = 0;
    rXpos = 0.0f;
    rYpos = 0.0f;
    rFoward = 0;
    rBack = 0;
    rLeft = 0;
    rRight = 0;
    rLegs = 90;
    upLeg = 0;
    downLeg = 1;
}


void Robot::display(double bullet)
{
    this->updateRobotPos();
    this->robotMove();
    this->updateLangue();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);

//___________________Tete _________________________
//______________Tete _________________________
glPushMatrix();

    glScalef(0.2, 0.2, 0.2);
    glPushMatrix();
    /* Active le z-buffer */
        glEnable(GL_DEPTH_TEST);

        /* Activation des couleurs */
        glEnable(GL_COLOR_MATERIAL);

        /* d�finit la couleur d'effacement et la couleur de fond */
        glClearColor(0.0, 0.0, 0.0, 0.0);

        /* Activation des lumi�res */
        //glEnable(GL_LIGHTING);          // Activation du mode
        //glEnable(GL_LIGHT0);            // Activation lumi�re n�0
        //glEnable(GL_LIGHT1);            // Activation lumi�re n�1
        //glEnable(GL_LIGHT2);            // Activation lumi�re n�2

        /* Les normales (cr�es par glNormal(*)) sont automatiquement unitaires */
        glEnable(GL_NORMALIZE);


        /* Activation du mode ombrage (shading) et lissage (smooth) des couleur */
        glShadeModel(GL_SMOOTH);

        /*  d�finit la taille d'un pixel*/
        glPointSize(2.0);
        glTranslatef(rYpos, 13, rXpos);
            glPushMatrix();
                glTranslatef(0, 2, 0);
                glRotatef(90,0,0,1);
                glColor3f(0.2f, 0.2f, 0.2f);
                glScalef(0.7, 0.5, 0.5);
                glutSolidSphere(2,20,20);
            glPopMatrix();

            //yeux
            glPushMatrix();
                glPushMatrix();
                    //Blanc des yeux
                    glPushMatrix();
                        glTranslatef(-0.3, 2.3, 0.85);
                        glRotatef(0,0,0,1);
                        glColor3f(1.0f, 1.0f, 1.0f);
                        glScalef(0.08, 0.08, 0.08);
                        glutSolidSphere(3.5,20,20);
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.3, 2.3, 0.85);
                        glRotatef(0,0,0,1);
                        glColor3f(1.0f, 1.0f, 1.0f);
                        glScalef(0.08, 0.08, 0.08);
                        glutSolidSphere(3.5,20,20);
                    glPopMatrix();
                glPopMatrix();

                //pupille
                glPushMatrix();
                    glPushMatrix();
                        glTranslatef(-0.3, 2.2, 1.12);
                        glRotatef(0,0,0,1);
                        glColor3f(1.0f, 0.0f, 0.0f);
                        glScalef(0.007, 0.007, 0.007);
                        glutSolidSphere(3.5,20,20);
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.3, 2.2, 1.12);
                        glRotatef(0,0,0,1);
                        glColor3f(1.0f, 0.0f, 0.0f);
                        glScalef(0.007, 0.007, 0.007);
                        glutSolidSphere(3.5,20,20);
                    glPopMatrix();
                glPopMatrix();

                //cheveux
                glPushMatrix();

                    glPushMatrix();
                        glTranslatef(-0.8, 2.2, 0);
                        glRotatef(250,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(-0.8, 2.2, 0);
                        glRotatef(230,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(-0.8, 2.4, 0);
                        glRotatef(210,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(-0.7, 2.7, 0);
                        glRotatef(190,0,0,1);
                        glScalef(0.8, 0.8, 0.8);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(-0.5, 3, 0);
                        glRotatef(170,0,0,1);
                        glScalef(0.8, 0.8, 0.8);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(-0.3, 3.3, 0);
                        glRotatef(150,0,0,1);
                        glScalef(0.8, 0.8, 0.8);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0, 3.5, 0);
                        glRotatef(135,0,0,1);
                        glScalef(0.8, 0.8, 0.8);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.5, 3.4, 0);
                        glRotatef(115,0,0,1);
                        glScalef(0.85, 0.85, 0.85);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.8, 3.1, 0);
                        glRotatef(95,0,0,1);
                        glScalef(0.8, 0.8, 0.8);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.9, 2.9, 0);
                        glRotatef(75,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.9, 2.6, 0);
                        glRotatef(55,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.9, 2.3, 0);
                        glRotatef(35,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.75, 2, 0);
                        glRotatef(15,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.6, 1.8, 0);
                        glRotatef(-0.05,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                     glPushMatrix();
                        glTranslatef(0.4, 1.75, 0);
                        glRotatef(-15,0,0,1);
                        glScalef(0.75, 0.75, 0.75);
                        glBegin(GL_TRIANGLES);
                            glColor3f(0.1, 0.2, 0.3);
                            glVertex3d(0, 0, 0);
                            glVertex3d(1, 0, 0);
                            glVertex3d(0, 1, 0);
                        glEnd();
                    glPopMatrix();
                glPopMatrix();

                //Sourcil
                glPushMatrix();
                    glRotatef(90,0,1,0);
                    glPushMatrix();
                        glTranslatef(-0.9, 2.67, -0.4);
                        gluCylinder(quad, 0.05, 0.05, 0.85, 20, 20);
                    glPopMatrix();
                glPopMatrix();

                //Bouche
                glPushMatrix();
                    glPushMatrix();
                        glTranslatef(0, 1.45, 0.66);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.0f, 0.0f, 0.0f);
                            glScalef(1.6, 0.4, 1);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0, 1.45, 0.66);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.0f, 0.0f, 0.0f);
                            glScalef(1.6, 0.4, 1);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0, 1.6, 0.71);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.3f, 0.3f, 0.3f);
                            glScalef(2, 0.2, 1);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix();
                        glTranslatef(0, 1.3, 0.62);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.3f, 0.3f, 0.3f);
                            glScalef(2, 0.2, 1);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix();
                        glTranslatef(-0.45, 1.43, 0.78);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.3f, 0.3f, 0.3f);
                            glScalef(0.2, 0.46, 0.5);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix();
                        glTranslatef(0.45, 1.43, 0.78);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.3f, 0.3f, 0.3f);
                            glScalef(0.2, 0.46, 0.5);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix();
                        glTranslatef(0, 1.45, 0.69);
                        glPushMatrix();
                            glRotatef(15,1,0,0);
                            glColor3f(0.737255f, 0.560784f, 0.560784f);
                            glScalef(0.8, 0.2, langue);
                            glutSolidCube(0.5);
                        glPopMatrix();
                    glPopMatrix();

                glPopMatrix();


                //________________Bras gauche____________________________________
    glPushMatrix();

        glPushMatrix(); // �paule
            glTranslatef(2.1, -0.1, 0);
            glRotatef(0, 0, 1, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidSphere(0.3,20,20);
        glPopMatrix();

        glPushMatrix(); // bras
            glTranslatef(2.1, -0.1, 0);
            glRotatef(rLegs,0,0,1);
            glColor3f(0.2f, 0.2f, 0.2f);
            gluCylinder(quad, 0.2, 0.2, 5, 20, 20);

            glPushMatrix(); // Main
                glTranslatef(0, 0, 5);
                glRotatef(0, 0, 1, 0);
                glColor3f(0.2f, 0.2f, 0.2f);
                glutSolidSphere(0.3,20,20);
            glPopMatrix();

        glPopMatrix();



    glPopMatrix();


    //________________Bras droit___________________________________

    glPushMatrix();

        glPushMatrix();//Bras
            glTranslatef(-2.1, 0.1, 0);
            glRotatef(-rLegs,0,1,0);
            glColor3f(0.2f, 0.2f, 0.2f);
            gluCylinder(quad, 0.2, 0.2, 5, 20, 20);

            glPushMatrix(); // Main
                glTranslatef(0, 0, 5);
                glRotatef(0, 0, 1, 0);
                glColor3f(0.2f, 0.2f, 0.2f);
                glutSolidSphere(0.3,20,20);
            glPopMatrix();


//_________________________________ GUN _________________________________
            glPushMatrix();
            glScalef(3.5,3.5,3.5);
            glTranslatef(0,-1.37,-3.3);
            glRotatef(90,0,1,0);
            glColor3f(0.2f,0.2f,0.2f);

//________________ Canon ____________________

glPushMatrix();
    glPushMatrix();
        glTranslatef(-5, 1.5, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(1, 0.05, 0.15);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5, 1.55, 0);
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(1, 0.05, 0.15);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5, 1.525, -0.035);
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(1, 0.05, 0.15);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-5, 1.525, 0.035);
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(1, 0.05, 0.15);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//_________________________________________

//_____________ Chargeur __________________


    glPushMatrix();
        glTranslatef(-4.81, 1.425, 0);
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(0.5, 0.25, 0.15);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//_______________________________________

//_____________ Mire __________________


    glPushMatrix();
        glTranslatef(-4.77, 1.574, 0);
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
            glColor3f(0.0f, 0.0f, 0.0f);
            glScalef(0.05, 0.05, 0.005);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

//_______________________________________

    //_________________ Balle ________________
    glPushMatrix();
        glTranslatef(-5, 1.525, 0.0);
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
            glColor3f(0.0f, 1.0f, 0.0f);
            glScalef(0.1, 0.1, 0.1);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();
    //________________________________________

glPopMatrix();
//___________________________________________

            glPopMatrix();
        glPopMatrix();

        glPushMatrix();//Epaule
            glTranslatef(-2.1, 0.1, 0);
            glRotatef(0, 0, 1, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidSphere(0.3,20,20);
        glPopMatrix();

    glPopMatrix();

        //CORPS

        glPushMatrix();
            glTranslatef(0, 0, 0);
            glRotatef(90 ,1 ,0 ,0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidCone(2, 8, 20, 30);
        glPopMatrix();

        glTranslatef(0, -4, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glScalef(5.5, 15, 5.5);
            glutSolidCube(0.5);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, -8, 0);
            glRotatef(270 ,1 ,0 ,0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidCone(2, 8, 20, 30);
        glPopMatrix();

        //COU

       glPushMatrix();
            glTranslatef(0, 1, 0);
            glRotatef(90, 1, 0, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            gluCylinder(quad, 0.4, 0.4, 3, 20, 20);
        glPopMatrix();
    //Jambe Gauche
    glPushMatrix();

    glPushMatrix();
            glTranslatef(1.75, -8, 0);
            glRotatef(-rLegs,1,0,0);
            glColor3f(0.2f, 0.2f, 0.2f);
            gluCylinder(quad, 0.3, 0.3, 4, 10, 10);

            glPushMatrix();

            glTranslatef(0, 0, 4);
                glColor3f(0.2f, 0.2f, 0.2f);
                glScalef(2, 4, 1);
                glutSolidCube(0.5);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0, 0, 3.75);
                glRotatef(0, 0, 1, 0);
                glColor3f(0.2f, 0.2f, 0.2f);
                glutSolidSphere(0.35,20,20);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
            glTranslatef(1.75, -8, 0);
            glRotatef(0, 0, 1, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidSphere(0.3,20,20);
        glPopMatrix();

    glPopMatrix();
    //Jambe Droite
    glPushMatrix();

    glPushMatrix();
            glTranslatef(-1.75, -8, 0);
            glRotatef(rLegs,1,0,0);
            glColor3f(0.2f, 0.2f, 0.2f);
            gluCylinder(quad, 0.3, 0.3, 4, 10, 10);

        //pied
        glPushMatrix();

        glTranslatef(0, 0, 4);
            glColor3f(0.2f, 0.2f, 0.2f);
            glScalef(2, 4, 1);
            glutSolidCube(0.5);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, 3.75);
            glRotatef(0, 0, 1, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidSphere(0.35,20,20);
        glPopMatrix();

        glPopMatrix();

    glPushMatrix();
            glTranslatef(-1.75, -8, 0);
            glRotatef(0, 0, 1, 0);
            glColor3f(0.2f, 0.2f, 0.2f);
            glutSolidSphere(0.3,20,20);
        glPopMatrix();




    glPopMatrix();

    glPopMatrix();


glPopMatrix();

}

void Robot::updateLangue()
{
    if(this->langue > 3)
    {
        this->up = true;
        this->down = false;
    }

    if(this->langue < 0)
    {
        this->up = false;
        this->down = true;
    }

    if(this->up)
    {
        this->langue -= 0.01;
    }

    if(this->down)
    {
        this->langue += 0.01;
    }
}

void Robot::updateRobotPos()
{
    if (rFoward){
        this->rXpos += 1.0;
        rFoward = 0;
    }
    if (rRight){
        this->rYpos -= 1.0;
        rRight = 0;
    }
    if (rLeft){
        this->rYpos += 1.0;
        rLeft = 0;
    }
    if (rBack){
        this->rXpos -= 1.0;
        rBack = 0;
    }
}
void Robot::robotMove()
{

        if(this->rLegs > 50)
        {

            this->upLeg = true;
            this->downLeg = false;
        }

        if(this->rLegs < -50)
        {

            this->upLeg = false;
            this->downLeg = true;
        }

        if(this->upLeg)
        {
            this->rLegs -= 1;
        }

        if(this->downLeg)
        {
            this->rLegs+=1;
        }



}

void Robot::SetTexture(int wall, GLuint texture)
{
    textures[wall] = texture;
}

/*void Robot::updateLegAngle()
{
    if(this->angle1 > 50)
    {
        this->upLeg = true;
        this->downLeg = false;
    }

    if(this->angle1 < -50)
    {
        this->upLeg = false;
        this->downLeg = true;
    }

    if(this->upLeg)
    {
        this->angle1 -= 20;
    }

    if(this->downLeg)
    {
        this->angle1 += 20;
    }
*/
