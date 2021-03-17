#ifndef ENVIRONMENTOGL_H
#define ENVIRONMENTOGL_H
#include <gl/gl.h>
#include <GL/GLU.h>


#include "object3D.h"
#define PI 3.14159265

class EnvironmentOGL
{
public:
    EnvironmentOGL();
    virtual ~EnvironmentOGL();
    void initializer(float rcamera, vector3d pLocation,vector3d color);
    void render();
    void resize(int width, int height);
    void drawarrow3D( vector3d A,  vector3d B, vector3d color, double cota1,double R=0.01);

    float cameraX,  cameraZ, cameraY,   mouseX,mouseY, camerafactor,angle;
    float Rcamera, phiCamera, thetaCamera;

    float pLocationX, pLocationY, pLocationZ;

    vector3d red = {1,0.0,0.0};
    vector3d green={0.0,1,0.0};
    vector3d blue= {0.0,0.0,1};

};

#endif // EnvironmentOGL_H
