#include "Component.h"


Component::Component(string name_object, vector3d origin)
{
    name = name_object;
    component.moveOrigin(origin)
    component.read_object(name_objet);
}

Component::~Component()
{
    //dtor
}
