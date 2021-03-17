#include "Robot.h"

Robot::Robot(std::string name_robot)
{
 	name = name_robot;

}

void Robot::initializar(){

    load_link = new object3D("Base.STL", {0,0,0}, {0,0,0}, {0.89,0.74,.003});
    Links.push_back(load_link);
    delete load_link;

}

void Robot::configurationInit(){

    THList.push_back(TH.rotaryHZ(0,{0,0,0}));
    THList.push_back(TH.rotaryHX(0,{0,0,0}));
}
Robot::~Robot(){}
