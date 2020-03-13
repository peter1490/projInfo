//
// Created by mathi on 2018-07-04.
//

#include "../include/House.h"

void House::draw(double x, double y, double z, double width, double height, double depth)
{
    GLuint texture= SOIL_load_OGL_texture("img/house.jpg",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x - width, y + height,z + depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x - width, y + height,z - depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x + width, y + height,z - depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x + width, y + height,z + depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x - width, y - height,z + depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x - width, y - height,z - depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x + width, y - height,z - depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x + width, y - height,z + depth);
    glEnd();


    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x + width, y + height,z + depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x + width, y + height,z - depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x + width, y - height,z - depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x + width, y - height,z + depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x - width, y + height,z + depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x - width, y + height,z - depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x - width, y - height,z - depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x - width, y - height,z + depth);
    glEnd();


    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x + width, y + height,z - depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x + width, y - height,z - depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x - width, y - height,z - depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x - width, y + height,z - depth);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(x + width, y + height,z + depth);
    glTexCoord2f(0.0f, 32.0f);
    glVertex3d(x + width, y - height,z + depth);
    glTexCoord2f(32.0f, 32.0f);
    glVertex3d(x - width, y - height,z + depth);
    glTexCoord2f(32.0f, 0.0f);
    glVertex3d(x - width, y + height,z + depth);
    glEnd();
}
