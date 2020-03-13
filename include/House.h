//
// Created by mathi on 2018-07-04.
//

#ifndef PROJETINFOGRAPHIE_HOUSE_H
#define PROJETINFOGRAPHIE_HOUSE_H

#include <GL/glut.h>

#include <SOIL/SOIL.h>
#include <stdio.h>
#include "Rectangle.h"


class House
{
    public:
        void draw(double x, double y, double z, double width, double height, double depth);
};


#endif //PROJETINFOGRAPHIE_HOUSE_H
