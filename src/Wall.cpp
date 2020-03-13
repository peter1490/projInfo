#include "../include/Wall.h"

Wall::Wall()
{

};

void Wall::draw()
{
    glPushMatrix();
        glTranslatef(0.45, 1.43, 0.78);
        glPushMatrix();
            glRotatef(15,1,0,0);
            glColor3f(0.3f, 0.3f, 0.3f);
            glScalef(0.2, 0.46, 0.5);
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();
}
