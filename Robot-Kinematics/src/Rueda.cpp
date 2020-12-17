#include "Rueda.h"
#include <iostream>
#include <windows.h>
Rueda::Rueda(vector3d pos)
{
    rueda = new object3D(pos);
    rueda->read_object("pikachu.stl");
    rueda->colorObject = {1,0,0,1};
}

Rueda::~Rueda()
{

}

void Rueda::render(){

    //rueda->renderLines();
    rueda->renderSolid();
}

void Rueda::move(vector3d moveAt){

	rueda->traslatarOrigin(moveAt);

}
