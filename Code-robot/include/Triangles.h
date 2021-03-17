#ifndef TRIANGLES_H
#define TRIANGLES_H
#include "vector3d.h"

class Triangles: public vector3d
{
    public:
        Triangles();
        Triangles(vector3d _p1, vector3d _p2, vector3d _p3);
        Triangles(vector3d nom, vector3d _p1, vector3d _p2, vector3d _p3);
        vector3d nomalV();
		void assigned(vector3d nom, vector3d _p1, vector3d _p2, vector3d _p3);
        vector3d p[3];
        vector3d normal;

        virtual ~Triangles();
};

#endif // TRIANGLES_H
