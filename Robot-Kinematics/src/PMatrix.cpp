
#include "PMatrix.h"

using namespace std;

//((c -.-))
/**
*   @brief | Class for matrix processing
*/

/**
//// *********************************************************************************************************************************
*                  @name            | Constructors
*               | PMatriz( )        | Generate a default matrix
*               | PMatrix( n )      | Generate a matrix of dimensions n x n
*       @param  | _n                | Number of columns and rows
*               | PMatrix( n , m )  | Generate a matrix of n x m
*       @param  | _row              | Number of rows
*       @param  | _col              | Number of columns
*/
//// *********************************************************************************************************************************
//// *********************************************************************************************************************************
/**
*   @name       | Destructor
*/
//// *********************************************************************************************************************************
//// *********************************************************************************************************************************
/**
*                   @name       | Treatment and resizing of matrices
*               | mZero         |   Generate matrix with zeros
*               | oneFullOne    |   Generate matrix with ones
*               | mIdenty       |   Generate identity matrix
*               | mRedim        |   Resize the array with n' x m'
*       @param  | _row          |   Number of rows
*       @param  | _col          |   Number of columns
*               | mShow         |   Show matrix content
*               | mEntry        |   Allows access to the address of the matrix elements
*                                   and modify them by their position
*               | mFullIndenty  |   Complete an identity matrix with an already established matrix
*               | mInversaGauss |   Return matrix inverse by method of gauss-jordan
*               | mInversa      |   Return matrix inverse -short
*       @param  | show          |   View the intermediate matrices in the process
*               | mExtendIdenty |   Extend a matrix with an identity matrix
*
*/
//// *********************************************************************************************************************************
//// *********************************************************************************************************************************
/**
*   @name       | Operations and basics comparisons of the theory of matrices
*               | Operator =    |   Assign the values of matrix an other, if and only if,
*                                   are the same size
*       @param  | PMatrix &M    |   Object orientations PMatrix to their address
*               | Operator +    |   Matrix Addition
*       @param  | PMatrix &M    |
*               | Operator -    |   Matrix subtraction
*       @param  | PMatrix &M    |
*               | Operator |=   |   Force matrix resize with a matrix to of higher size
*       @param  | PMatrix &M    |
*               | Operator <<   |   Assembles one matrix next to another
*       @param  | PMatrix &M    |
*               | Operator *=   |   Assign the value of the matrix multiplication through your address
*       @param  | PMatrix &M    |
*               | Operator *    |   Matrices multiply and return a new matrix
*       @param  | PMatrix &M    |
*               | Operator *    |   Matrix multiply for one scalar and return a new matrix
*       @param  | PMatrix &M    |
*/
//// *********************************************************************************************************************************

/**
 *************************************************************************************************************************************
 * Constructors
 *************************************************************************************************************************************
 */
PMatrix::PMatrix(){
    row = col = 2;
    createMatrix(row, col);
    zero();
}
PMatrix::PMatrix(vector3d a){
    row = 3;
    col = 1;
    createMatrix(row, col);
    zero();

    dm[0][0] = a.x;
    dm[1][0] = a.y;
    dm[2][0] = a.z;
}
PMatrix::PMatrix(int _n){
    row = col = _n;

    createMatrix(row, col);
    zero();
}
PMatrix::PMatrix(int _row, int _col){
    row = _row;
    col = _col;

    createMatrix(row, col);
    zero();
}

void PMatrix::createMatrix(int _row, int _col){
    if(_row > 0 && _col > 0){
        dm = new double*[_row];
        for(int i = 0; i < _row; i++) dm[i] = new double[_col];
    }
}
/**
 ***************
 **********************************************************************************************************************
 * Destroyers
 *************************************************************************************************************************************
 */
PMatrix::~PMatrix(){}

/**
 *************************************************************************************************************************************
 * Treatments and matrices resize functions
 *************************************************************************************************************************************
 */
void PMatrix::zero(){
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            dm[i][j] = 0;
}
void PMatrix::fullOneDiagonal(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            dm[i][j] = 1;
        }
    }
}
void PMatrix::identy(){
    if(row == col)
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(i==j){ dm[i][j] = 1;
                } else { dm[i][j] = 0; }
            }
}
void PMatrix::createNewIdentity(int _n){
    redim(_n,_n);
    zero();
    if(row == col)
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(i==j){ dm[i][j] = 1;
                } else { dm[i][j] = 0; }
            }
}
void PMatrix::redim(int _row, int _col){
    if(_row > 0 && _col > 0){

        row2 = row;
        col2 = col;

        row = _row;
        col = _col;

        if(_row > 0 && _col > 0){

            dma = new double*[row];
            for(int i = 0; i < row; i++){
                    dma[i] = new double[col];}

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    dma[i][j] = 0; }
            }
            /// variable change

            if(col2 < _col){
                col = col2;
            }
            if(row2 < _row){
                row = row2;
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    dma[i][j] = dm[i][j];
                }
            }
            row = _row;
            col = _col;

            delete[] dm;

            createMatrix(row, col);
            zero();

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    this->entry(i,j) = dma[i][j];
                }
            }
            delete[] dma;
        }
        else{
            row = row2;
            col = col2;
        }
    }
    else{
        cout << "Bad Data" << endl;
    }
}
void PMatrix::show(){
    cout << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << dm[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
double& PMatrix::entry(int _row, int _col){
 return _row >=0 && _col >=0 ? dm[_row][_col]: dm[0][0];
}
void PMatrix::dataEntry(){
    int rows = 1;
    int columns = 1;
    do{
        cout << "Number of Rows: ";
        cin >> rows;
        cout << "Number of Columns: ";
        cin >> columns;
    }while(rows<=0 || columns<=0);
    redim(rows, columns);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0 ; j < columns; j++){
            cout << "(" << i << "," << j << "): ";
            cin >> this->entry(i,j);
        }
    }
    cout << "Okay" << endl;
}
void PMatrix::fullIdenty(){
    cout << row << endl;
    cout << col << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j){
                if( dm[i][j] == 0){
                    dm[i][j] = 1;
                }
            }
        }
    }
}
PMatrix PMatrix::transpose(){

    PMatrix B(col,row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            B.entry(j,i) = dm[i][j];
        }
    }
    return B;
}
PMatrix PMatrix::inverseGauss(bool show){

    /*
    Matrix inverse by gauss-jordan method

    If the determinant of matrix A is equal to zero not exist the inverse
    */

    double d =(*this).determinante();

    PMatrix extend;
    PMatrix inver(row, col);
    inver.identy();
    PMatrix vect;

    vect.zero();

    if (d==0) {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout<<  "|| Does not exist       ||"<<endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        return vect;
    }

    if(row != col){
        cout << "Matrix does is not square" << endl;
        return vect;
    }

    if(row >= 1 ){

        extend |= extendIdenty();
        vect.redim(row ,1);

        /// Create zeros under of the main diagonal
        for(int c = 0; c < col; c++){
            vect.fullOneDiagonal();
            for(int f = 0; f < row; f++){
                if(c == f){
                    for(int f1 = f; f1 < row; f1++){
                        if(extend.entry(f1,c)!=0){
                            vect.entry(f1, 0) = 1/extend.entry(f1, c);
                        }
                        for(int c1 = c; c1 < extend.col; c1++){
                            extend.entry(f1, c1) *= vect.entry(f1, 0);
                        }
                    }
                    for(int f1 = row-1; f1 > f; f1--){
                         if(extend.entry(f1,c) == 1){
                            for(int c1 = c; c1 < extend.col; c1++){
                                extend.entry(f1,c1) -= extend.entry(f,c1);
                            }
                        }
                    }
                    if(show)   extend.show();
                }

            }
        }

        /// Create zeros above of the main diagonal
        for(int c = col-1; c >= 0; c--){
            vect.fullOneDiagonal();
            for(int f = row-1; f >=0; f-- ){
                if(c == f){
                    for(int f1 = 0; f1 < row; f1++){
                        vect.entry(f1, 0) = (extend.entry(f1,c) != 0)? 1/extend.entry(f1,c) : 1;
                        for(int c1 = 0; c1 < extend.col; c1++){
                            extend.entry(f1,c1)*= vect.entry(f1,0);
                        }
                    }
                    for(int f1 = 0; f1 < f; f1++){
                        if(extend.entry(f1,c) == 1){
                            for(int c1 = 0; c1 < extend.col; c1++){
                                extend.entry(f1,c1) -= extend.entry(f,c1);
                            }
                        }
                    }
                    if(show)   extend.show();
                }
            }
         }

    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            inver.entry(i,j) = extend.entry(i,j+row);
        }
    }
    return inver;
}
PMatrix PMatrix::extendIdenty(){
    PMatrix B(col);
    B.identy();

    B |= (*this) << B;

    return B;
}
/**
 *************************************************************************************************************************************
 * Matrix handling
 *************************************************************************************************************************************
 */
double PMatrix::determinante(){
    double det = 0;

    if (row!=col && row > 0){
            cout << "Matrix Size Different  n¬m " << endl;
        return 0;
        }
    if( row == 1 ){
        det =  dm[0][0];
    }
    else if (row == 2) {
        det = dm[0][0]*dm[1][1]-dm[0][1]*dm[1][0];
    }
    else{
        for (int j=0; j < col; j++){
            det = det + dm[0][j]*pow(-1,j)*mij(0,j).determinante();
        }
    }
    return det;
 }
int PMatrix::size() const { return row*col; }
PMatrix PMatrix::mij(int a,int b){ // minor of a matrix

        int s = row - 1;
        PMatrix B(s,s); //reduced matrix

        for (int i=0; i<a;i++)
            for (int j=0; j<b;j++){
                B.dm[i][j]=dm[i][j]; //first part
            }

        for (int i=0; i<a;i++)
            for (int j=b+1; j<col;j++){
                B.dm[i][j-1]=dm[i][j];  // The columns are traversed
            }

        for (int i=a+1; i<row;i++)
            for (int j=0; j<b;j++){
                B.dm[i-1][j]=dm[i][j];  // The columns are crossed
            }

        for (int i=a+1; i<row;i++)
            for (int j=b+1; j<col;j++){
                B.dm[i-1][j-1]=dm[i][j]; // The columns are traversed
            }
        return B;
}
PMatrix PMatrix::inverse(){
    double d =(*this).determinante();
    PMatrix B(1,1);

    if (d==0) {
            B.redim(1,1);
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout<<  "|| Does not exist       ||"<<endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

    }
    if( row > 2) {
        B.redim(row,row);
        for( int i = 0; i < row; i++)
            for(int j = 0; j < row; j++){
                B.dm[j][i]= (1.0/d) * (pow(-1, i+j)*mij(i,j).determinante());
             }

    }
    else if( row == 2 ) {
        B.redim(row,row);
        B.dm[0][0]=(1.0/d)*dm[1][1];
        B.dm[0][1]=-(1.0/d)*dm[0][1];
        B.dm[1][0]=-(1.0/d)*dm[1][0];
        B.dm[1][1]=(1.0/d)*dm[0][0];

    }
    else if( row == 1 ) {
        B.redim(1,1);
        B.dm[0][0]=1/dm[0][0];
    }
    return B;
}
/**
 *************************************************************************************************************************************
 * Operations and basics comparison of the theory of matrices
 *************************************************************************************************************************************
 */
PMatrix& PMatrix::operator =( const PMatrix &M ){
    /**
    * Let A and B be matrices of the same size
    * can be assigned A = B by fulfilling that
    * a (i, j) = b (i, j)
    */
    if( M.row > 0 && M.col > 0 && row == M.row && col == M.col){
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                dm[i][j] = M.dm[i][j];
            }
        }
        /// cout << "Okay" << endl;
        return *this;
    }
    else{
        cout << "Matrix Size Different = " << endl;
        return *this;
    }
}
PMatrix& PMatrix::operator |=(const PMatrix &M){
 if( M.row > 0 && M.col > 0){
    this->redim(M.row,M.col);
    for (int i = 0; i < row ; i++)
    {
        for (int j = 0; j < col; j++)
        {
            dm[i][j] = M.dm[i][j];
        }
    }
    /// cout << "Okay" << endl;
    return *this;
 }
 else{
    cout << "Empty Element" << endl;
    cout << "Matrix defined in [3,3]" << endl;
    this->redim(3,3);
    this->zero();
    return *this;
 }
}
PMatrix PMatrix::operator + (const PMatrix &M){
    /**
    *   Let A, B and C matrices of m x n both
    *   A = a(i,j)
    *   B = b(i,j)
    *   C = c(i,j)
    *
    *   C = A + B
    *       C(i,j) = a(i,j) + b(i,j)
    *
    */
    if ( M.row > 0 && M.col > 0 && row == M.row && col == M.col)
    {
        PMatrix Ax(M.row, M.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Ax.dm[i][j] = dm[i][j] + M.dm[i][j];
            }
        }
        return Ax;
    }
    else {
        PMatrix Ax(1,1);
        cout << "Matrix Size Different + " << endl;
        return Ax;
    }
}
PMatrix PMatrix::operator - (const PMatrix &M){
    /**
    *   Let A, B and C matrices of m x n both
    *   A = a(i,j)
    *   B = b(i,j)
    *   C = c(i,j)
    *
    *   C = A - B
    *       C(i,j) = a(i,j) - b(i,j)
    *
    */
    if ( M.row > 0 && M.col > 0 && row == M.row && col == M.col)
    {
        PMatrix Ax(M.row, M.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Ax.dm[i][j] = dm[i][j] - M.dm[i][j];
            }
        }
        return Ax;
    }
    else {
        PMatrix Ax(1,1);
        cout << "Matrix Size Different - " << endl;
        return Ax;
    }
}
bool PMatrix::operator == (const PMatrix &M){
    if(M.row > 0 && M.col > 0 && (row*col) == (M.row*M.col)){
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(!(dm[i][j] == M.dm[i][j])){
                    return false;
                }
            }
        }
    }
    else{ return false; }
    return true;
}

PMatrix operator*(double e, PMatrix M){
    /**
    *   Let A = a(i,j) and e a scalar
    *
    *   e*A = e * a(i,j)
    *
    *   Restriction
    *   B = e * A;
    */
    PMatrix Ax(1, 1);
    if(M.row > 0 && M.col > 0){
        Ax.redim(M.row, M.col);
        for (int i = 0; i < M.row; i++)
        {
            for (int j = 0; j < M.col; j++)
            {
                Ax.entry(i,j) = e*M.entry(i,j);
            }
        }
    }
    return Ax;
}
PMatrix& PMatrix::operator *=(double e){
    /**
    *   Let A = a(i,j) and e a scalar
    *
    *   e*A = e * a(i,j)
    *
    *   Function restriction
    *   A = e * A;
    *
    */
    for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                this->dm[i][j] = e*this->entry(i,j);
            }
        }
    return *this;
}
PMatrix PMatrix::operator *(PMatrix M){
    /**
    *   Let A and B matrices
    *   A = a(i,j)   of m x n members
    *   B = b(i,j)   of n x p members
    *   C = A X B
    *      C(i,j) = (row i of A)*(column j of B)
    *
    *      C(i,j) = a(i,1)*b(1,j) + a(i,2)*b(2,j) + ... + a(i,n)*b(n,j)
    */
    if(col == M.row){
        PMatrix Ax(row, M.col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < M.col; j++)
            {
                double sum = 0;
                for (int k = 0; k < col; k++)
                {
                    sum = sum + this->entry(i,k)*M.entry(k,j);
                }
                Ax.entry(i,j)= sum;
            }
        }
        return Ax;
    }
    else{
        PMatrix Ax(3,3);
        cout << "Matrix Size Different * Column != Row " << endl;
        return Ax;
    }
}
PMatrix PMatrix::operator <<(const PMatrix &M){
    int rows;
    int rows2;
    rows = rows2 = this->row;

    if(rows < M.row)
        rows = M.row;

    if( rows2 > M.row )
        rows2 = M.row;

    PMatrix Ax(rows, col + M.col);
    Ax.zero();
    for(int i = 0; i < rows2; i++ ){
        for(int j = 0; j < this->col; j++){
                Ax.entry(i,j) = this->dm[i][j];
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = col; j < col + M.col; j++)
        {
            Ax.entry(i,j) = M.dm[i][j-col];
        }
    }
    return Ax;
}
double PMatrix::magnitude(){
    double r;
    r = (entry(0,0)*entry(0,0))+(entry(1,0)*entry(1,0))+(entry(2,0)*entry(2,0));
    r = sqrt(r);
    return r;
}
