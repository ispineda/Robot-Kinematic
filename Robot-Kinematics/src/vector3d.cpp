#include "vector3d.h"
#include "PMatrix.h"
#include <iostream>
using namespace std;

vector3d::vector3d(double _x, double _y, double _z): x(_x), y(_y), z(_z){ t = 0; };
vector3d::vector3d(double _x, double _y, double _z, double _t): x(_x), y(_y), z(_z), t(_t){};
vector3d::vector3d(){
    x=0;
    y=0;
    z=0;
};

vector3d vector3d::operator+(const vector3d &p)const
{
    return vector3d(x + p.x, y + p.y, z + p.z, t + p.t);
}

vector3d vector3d::operator*(const vector3d &p)const
{
    return vector3d(y*p.z-z*p.y, z*p.x-x*p.z,x*p.y-y*p.x);
}
vector3d vector3d::operator-(const vector3d &p) const
{
    return vector3d(x - p.x, y - p.y, z - p.z, t - p.t);
}

vector3d operator*(const double &s,const vector3d &p)
{
    return vector3d(s * p.x, s * p.y, s * p.z, s * p.t);
}

int vector3d::operator==(const vector3d &p)
{
    return ((x == p.x) && (y == p.y) && (z == p.z) && (t == p.t));
}

int vector3d::operator!=(const vector3d &p)
{
    return !(*this == p);
}
double& vector3d::operator[](int i)
{
    return ((i == 0) ? x : ((i == 1) ? y : ((i==2) ? z : t)));
}
double vector3d::scalarProduct(const vector3d &p)
{
    return (x*p.x + y*p.y + z*p.z + t*p.t);
}

double vector3d::magnitude() const
{
    return sqrt(x*x + y*y + z*z + t*t);
};
vector3d& vector3d::normalize()
{
    double a=magnitude();
    if (a!=0)
    {
        x=x/a;
        y=y/a;
        z=z/a;
        t = 0;
    };
    return *this;
}
vector3d&  vector3d::operator =( const vector3d &B)
{
    x=B.x;
    y=B.y;
    z=B.z;
    t=B.t;
    return *this;
}
vector3d::~vector3d() {}
void vector3d::show(bool _t = false)
{
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
    if(_t) cout<<t<<endl;
}

double vector3d::angleInVectors(const vector3d &B)
{
/**
    Sea A y B vectores de R^3 entonces el producto punto define

    A * B = |A|*|B|* cos(theta)
al despejar

    theta = arcos(   A*B   )
                   ------
                   |A|*|B|
*/
    vector3d av(x,y,z);
    double r = av.scalarProduct(B);
    double s = av.magnitude()*B.magnitude();
    if(s!=0)
        return acos(r/s);
    return 0;
}

vector3d vector3d::tripleProduct(vector3d B, vector3d C){
/**
    Equivalente a A x (B x C)
    y a A*(B*C) con el operador sobrecargado
*/
    vector3d r;
    r = (this->scalarProduct(C))*B - (this->scalarProduct(B))*C;
    return r;
}



bool vector3d::isParallel(const vector3d &B)
{
    vector3d r;
    vector3d d(this->x, this->y, this->z);
    r.nullVector();

    r = d*B;
    if(r.x == 0 && r.y == 0 && r.z == 0){
        return true;
    }
    return false;
}

vector3d& vector3d::nullVector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->t = 0;
    return *this;
}


