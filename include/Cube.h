//
// Created by mathi on 2018-07-04.
//

#ifndef PROJETINFOGRAPHIE_CUBE_H
#define PROJETINFOGRAPHIE_CUBE_H

#include <GL/glut.h>


class Cube
{
    public:
        Cube(double x, double y, double z, double depth);
        void draw();
        enum faces {
            FRONT,
            BACK,
            LEFT,
            RIGHT,
            TOP,
            BOTTOM
        };
        void setColor(faces type, GLubyte r, GLubyte g, GLubyte b);

    private:
        double x;
        double y;
        double z;
        double depth;
        GLubyte color[6][3] = {{0}};
};


#endif //PROJETINFOGRAPHIE_CUBE_H
