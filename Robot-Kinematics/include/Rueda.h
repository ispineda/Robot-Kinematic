#ifndef RUEDA_H
#define RUEDA_H
#include "vector3d.h"
#include "object3D.h"

class Rueda
{
    public:
    	
        Rueda(vector3d pos);
        virtual ~Rueda();
        void render();
        void move(vector3d moveAt);
        object3D* rueda;

};

#endif // RUEDA_H
