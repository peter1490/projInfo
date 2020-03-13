#ifndef MAP_H
#define MAP_H

#include <GL/glut.h>
#include <math.h>

#include <SOIL/SOIL.h>

#include "Camera.h"

class Map
{
    public:
        Map();
        // Stockage des r�f�rences aux textures
        GLuint Skybox[6];
        GLuint ListeTextures[20];
        void LoadTextures(void);
        void DrawGround(void);
        void DrawSkybox(Camera *cam);
        void DrawSun(double sunAngle);
        void DrawPortal1();
        void DrawPortal2();
        void DrawTree();
    protected:
    private:
        GLuint sunTexture;
        static GLfloat lightColor[4];
        static GLfloat lightPos[4];

        GLUquadricObj *quad = gluNewQuadric();

};

#endif // MAP_H
