#include "Triangles.h"

Triangles::Triangles(){
	p[0] = {1,0,0};
	p[1] = {0,1,0};
	p[2] = {0,0,1};
}

//Created object for triangles of stl object 
Triangles::Triangles(vector3d _p1, vector3d _p2, vector3d _p3)
{
    p[0] = _p1;
    p[1] = _p2;
    p[2] = _p3;
}

Triangles::~Triangles(){}

vector3d Triangles::nomalV(){
	vector3d v1, v2;
	v1 = p[1]-p[0];
	v2 = p[2]-p[0];
	normal = (v1*v2).normalize();
	return normal;
}