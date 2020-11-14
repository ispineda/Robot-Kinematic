#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <fstream>
#include <iostream>

#define PI 3.14159265

class object3D
{
    public:
        object3D();
        bool read_object(char* name);
        bool render_object();

        virtual ~object3D();

    	//ifstream fileObject;
};

#endif // OBJECT3D_H
