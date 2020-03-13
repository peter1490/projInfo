//
// Created by mathi on 2018-07-04.
//

#include "../include/Road.h"

GLfloat Road::lightColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat Road::lightPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};

Road::Road()
{
    this->sunTexture = 0;
}

void Road::draw(double sunAngle)
{
    /*glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);

    this->sunTexture = SOIL_load_OGL_texture("img/sun.jpg",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,sunTexture);
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
    glPopMatrix();*/
}
