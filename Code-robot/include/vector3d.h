#ifndef vector3d_H
#define vector3d_H
#include <math.h>

class vector3d
{
public:
    double x;
    double y;
    double z;
    double t;

    vector3d(double _x, double _y, double _z);
    vector3d(double _x, double _y, double _z, double _t);
    vector3d();
    ~vector3d();

    vector3d operator+(const vector3d &p)const;
    vector3d operator*(const vector3d &p)const;
    vector3d operator-(const vector3d &p)const;
    friend vector3d operator*(const double &s, const vector3d &p);
    int operator == (const vector3d &p);
    int operator != (const vector3d &p);
    double& operator[](int i);
    double scalarProduct(const vector3d &p);

    double magnitude() const;
    vector3d&  normalize();
    vector3d&  operator =( const vector3d &B);
    void show(bool _t);
    double angleInVectors(const vector3d &B);
    vector3d tripleProduct(vector3d B, vector3d C);

    bool isParallel(const vector3d &B);
    vector3d& nullVector();


};
#endif // vector3d_H
