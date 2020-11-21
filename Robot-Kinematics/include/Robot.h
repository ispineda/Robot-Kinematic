#ifndef ROBOT_H
#define ROBOT_H
#include <vector>
#include <cstdlib>
///Copyright (C) <2017>  <Eliseo Rivera> curso.tareas@gmail.com
class Robot
{
public:
    Robot();
    ~Robot();

    modelo3D *base;
    modelo3D *b1;
    modelo3D *b2;
    modelo3D *b3;
    modelo3D *b4;
    modelo3D *b5;
    modelo3D *b6;
    modelo3D *gripe;

    void inicializar();
    void renderizar();
    void configurarTH();

    void AplicarTHx(float theta, vector3d d);
    void AplicarTHy(float theta, vector3d d);
    void AplicarTHz(float theta, vector3d d);
    Matrix THx,THy,THz,TH,PTL,PTG;

    std::vector<Matrix> THList;
    std::vector<vector3d> Origenes;
    std::vector<modelo3D*> modelos;


    float theta1, theta2, theta3,theta4, theta5, theta6,theta7;
    float z1,x1,alpha1,z2,x2,alpha2,z3,x3,alpha3,z4,x4,alpha4,z5,x5,alpha5,z6,x6,alpha6;
    vector3d d1,d2,d3,d4,d5,d6,d7;

    void DefinirTHx(float theta, vector3d d);
    void DefinirTHy(float theta, vector3d d);
    void DefinirTHz(float theta, vector3d d);
    void  Drawarrow3D( vector3d A,  vector3d B, vector3d color, double cota1,double R) ;

    void MostrarTransformaciones ();

};

#endif // ROBOT_H
