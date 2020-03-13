//
// Created by mathi on 2018-07-04.
//

#ifndef PROJETINFOGRAPHIE_RECTANGLE_H
#define PROJETINFOGRAPHIE_RECTANGLE_H

#include <GL/glut.h>


class Rectangle
{
    public:
        Rectangle(double x, double y, double z, double width, double height, double depth);
        void draw();
        enum faces {
            FRONT,
            BACK,
            LEFT,
            RIGHT,
            TOP,
            BOTTOM
        };
        Rectangle *setColor(faces type, GLubyte r, GLubyte g, GLubyte b);
        Rectangle *setAllFaceColor(GLubyte r, GLubyte g, GLubyte b);

    private:
        double x;
        double y;
        double z;
        double depth;
        double height;
        double width;
        GLubyte color[6][3] = {{0}};
};


#endif //PROJETINFOGRAPHIE_RECTANGLE_H
