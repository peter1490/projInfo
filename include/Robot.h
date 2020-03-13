#ifndef ROBOT_H
#define ROBOT_H

#include <stdio.h>
#include <GL/glut.h>

#include "Cube.h"
#include "Rectangle.h"

class Robot
{
    public:
        Robot();
        void display(double bullet);
        void updateLangue();
        void wall();
        void SetTexture(int face, GLuint texture);
        char rFoward;
        char rBack;
        char rLeft;
        char rRight;
        void updateRobotPos();
        void robotMove();

    protected:

    private:
    int i;
    float rXpos;
    float rYpos;
    float rLegs;
    bool upLeg;
    bool downLeg;
    float langue;
    bool up = false;
    bool down = true;
    GLuint textures[6];

    GLUquadricObj *quad = gluNewQuadric();
};

#endif // ROBOT_H
