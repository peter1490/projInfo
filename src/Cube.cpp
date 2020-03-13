//
// Created by mathi on 2018-07-04.
//

#include "../include/Cube.h"

Cube::Cube(double x, double y, double z, double depth)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->depth = depth;
};

void Cube::draw()
{
    glBegin(GL_QUADS);
    glColor3ub(this->color[TOP][0],this->color[TOP][1],this->color[TOP][2]); //face rouge
    glVertex3d(this->x - this->depth, this->y + this->depth,this->z + this->depth);
    glVertex3d(this->x - this->depth, this->y + this->depth,this->z - this->depth);
    glVertex3d(this->x + this->depth, this->y + this->depth,this->z - this->depth);
    glVertex3d(this->x + this->depth, this->y + this->depth,this->z + this->depth);
    glEnd();


    glBegin(GL_QUADS);
        glColor3ub(this->color[BOTTOM][0],this->color[BOTTOM][1],this->color[BOTTOM][2]); //face rouge
        glVertex3d(this->x + this->depth, this->y + this->depth,this->z + this->depth);
        glVertex3d(this->x + this->depth, this->y + this->depth,this->z - this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z + this->depth);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(this->color[RIGHT][0],this->color[RIGHT][1],this->color[RIGHT][2]); //face rouge
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z + this->depth);
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z + this->depth);
    glEnd();


    glBegin(GL_QUADS);
        glColor3ub(this->color[LEFT][0],this->color[LEFT][1],this->color[LEFT][2]); //face rouge
        glVertex3d(this->x - this->depth, this->y + this->depth,this->z + this->depth);
        glVertex3d(this->x - this->depth, this->y + this->depth,this->z - this->depth);
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z + this->depth);
    glEnd();


    glBegin(GL_QUADS);
        glColor3ub(this->color[BACK][0],this->color[BACK][1],this->color[BACK][2]); //face rouge
        glVertex3d(this->x + this->depth, this->y + this->depth,this->z - this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z - this->depth);
        glVertex3d(this->x - this->depth, this->y + this->depth,this->z - this->depth);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(this->color[FRONT][0],this->color[FRONT][1],this->color[FRONT][2]); //face rouge
        glVertex3d(this->x + this->depth, this->y + this->depth,this->z + this->depth);
        glVertex3d(this->x + this->depth, this->y - this->depth,this->z + this->depth);
        glVertex3d(this->x - this->depth, this->y - this->depth,this->z + this->depth);
        glVertex3d(this->x - this->depth, this->y + this->depth,this->z + this->depth);
    glEnd();
}

void Cube::setColor(faces type, GLubyte r, GLubyte g, GLubyte b)
{
    this->color[type][0] = r;
    this->color[type][1] = g;
    this->color[type][2] = b;
}