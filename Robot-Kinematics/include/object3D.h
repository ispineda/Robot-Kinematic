#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <Triangles.h>
#include <PMatrix.h>
#include <gl/gl.h>
#include <GL/GLU.h>

#define PI 3.14159265

using namespace std;

class object3D
{
    public:
        object3D();
        object3D(double pos_x, double pos_y, double pos_z);
        bool read_object(const char* name);
        bool drawObject();
        void traslatarOrigin(vector3d tM);
        void moveOrigin(vector3d tO);

        virtual ~object3D();

    	ifstream fileObject;
    	int ntriangles;
    	Triangles* triangles;
    	vector3d Origin;

};

#endif // OBJECT3D_H
