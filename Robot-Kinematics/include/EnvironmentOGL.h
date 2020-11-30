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
    void initializer(float rcamera);
    void render();
    void resize(int width, int height);
    void  drawarrow3D( vector3d A,  vector3d B, vector3d color, double cota1,double R=0.01);

    float cameraX,  cameraZ, cameraY,   mouseX,mouseY, camerafactor,angle;
    float Rcamera, phiCamera, thetaCamera;
    float radians;

    vector3d redColor = {1,0.0,0.0};
    vector3d greenColor= {0.0,1,0.0};
    vector3d blueColor= {0.0,0.0,1};
    void drawarrow3Dmodel(const object3D &modelo);

};

#endif // EnvironmentOGL_H
