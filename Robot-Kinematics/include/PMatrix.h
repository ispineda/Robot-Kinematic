#ifndef PMATRIX_H
#define PMATRIX_H

#include <iostream>
#include <cmath>
#include <vector3d.h>

class PMatrix
{
    public:
        PMatrix();
        PMatrix(vector3d a);
        PMatrix(int _n);
        PMatrix(int _row, int _col);
        //PMatrix(const PMatrix &M);
        
        virtual ~PMatrix();

        void zero();
        void fullOneDiagonal();
        void identy();
        void createNewIdentity(int _n);
        void redim(int _row, int _col);
        void show();
        void fullIdenty();
        void dataEntry();
        double determinante();
        PMatrix transpose();
        PMatrix mij(int a, int b);
        int size() const;
        double& entry(int _row, int _col);
        PMatrix inversa();

        PMatrix& operator = ( const PMatrix &M);
        PMatrix& operator |= ( const PMatrix &M);
        PMatrix operator + ( const PMatrix &M);
        PMatrix operator - ( const PMatrix &M);
        bool operator == (const PMatrix &M);
        friend PMatrix operator*(double e, PMatrix M);
        PMatrix& operator *=(double e);
        PMatrix operator *(PMatrix M);
        PMatrix operator <<(const PMatrix &M);

        PMatrix inversaGauss(bool show = false);
        PMatrix extendIdenty();

        double magnitude();

        double **dm;
        double **dma;
        int row, col;
        int row2, col2;
    private:
        void createMatrix(int _row, int _column);
};

#endif // PMATRIX_H
