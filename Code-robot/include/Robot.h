#ifndef ROBOT_H
#define ROBOT_H
#include "object3D.h"
#include "vector3d.h"
#include "PMatrix.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#define  ITERA 1000

class Robot
{
    public:
        Robot(std::string name_robot);
        virtual ~Robot();
        void initializar();
        void configurationInit();
       	object3D *load_link;

       	PMatrix TH;
       	std::string name;
       	std::vector<PMatrix> THList;
       	std::vector<object3D*> Links;
       	std::vector<vector3d> Origins;
};

#endif // ROBOT_H
