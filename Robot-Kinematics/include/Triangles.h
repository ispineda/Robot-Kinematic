#ifndef TRIANGLES_H
#define TRIANGLES_H
#include "vector3d.h"

class Triangles: public vector3d
{
    public:
        Triangles();
        Triangles(vector3d p1, vector3d p2, vector3d p3);
        vector3d nomalV();

        vector3d p[3];
        vector3d normal;

        virtual ~Triangles();
};

#endif // TRIANGLES_H
