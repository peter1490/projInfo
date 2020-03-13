//
// Created by mathi on 2018-07-04.
//

#ifndef PROJETINFOGRAPHIE_ROAD_H
#define PROJETINFOGRAPHIE_ROAD_H

#include <GL/glut.h>

#include <SOIL/SOIL.h>
#include <stdio.h>


class Road
{
    public:
        Road();
        void draw(double sunAngle);

    private:
        GLuint sunTexture;
        GLuint roadTexture;
        static GLfloat lightColor[4];
        static GLfloat lightPos[4];
};


#endif //PROJETINFOGRAPHIE_ROAD_H
