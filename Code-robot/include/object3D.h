#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <Triangles.h>
#include <PMatrix.h>
#include <gl/gl.h>
#include <GL/GLU.h>
#include "vector3d.h"
#include <vector>


#define PI 3.14159265

using namespace std;

class object3D
{
    public:
        object3D();
        object3D(vector3d pos);
        object3D(std::string name_obj, vector3d position_obj, vector3d angular_obj, vector3d color);
        bool read_object(const char* name);
        bool renderSolid();
        bool renderPoints();
        bool renderLines();
        void traslatarOrigin(vector3d tM);
        void moveOrigin(vector3d tO);

        virtual ~object3D();


        vector3d colorObject;

    	ifstream fileObject;
    	int ntriangles;
    	Triangles* triangles;
    	vector3d Origin, ux, uy, uz;
        Triangles vT;

        float volume;
        std::string name;
        float mass;
        vector3d position;
        vector3d angulars;
        vector3d angular_velocity;
        vector3d linear_velocity;
        vector3d angular_acceleration;
        vector3d linear_acceleration;

};

#endif // OBJECT3D_H
