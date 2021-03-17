#ifndef COMPONENT_H
#define COMPONENT_H
#include <cstring>
#include "PMatrix.h"
#include "object3D.h"
#include "vector3d.h"

using namespace std;

class Component
{
    public:
        Component(string name_object);
        virtual ~Component();

        string name;
        object3D component;
};

#endif // COMPONENT_H
