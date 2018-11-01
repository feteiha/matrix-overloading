#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

/// constructor overloaded ------------------------------------------
/// constructor to allocate the memory and fill with garbage.
matrix::matrix( int row , int col )
{
    this->row = row;
    this->col = col;

    this->data = new int*[ this->row ];
    for ( int i = 0; i < this->row; i++ )
        this->data[ i ] = new int [ this-> col ];
}

/// constructor to allocate the memory and fill with value.
matrix::matrix( int row , int col , int value ) : matrix( row , col )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] = value;
}

/// constructor to allocate the memory and fill with array values.
matrix::matrix( int row , int col , int arr[] ) : matrix( row , col )
{
    int index = 0;
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] = arr[ index++ ];
}

/// copy constructor

matrix::matrix( matrix& mat ) : matrix( mat.row , mat.col )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] = mat.data[i][j];
}

/// setter ----------------------------------------------------------

matrix::setRow(int x)
{
    row = x;
}

matrix::setColomn(int x)
{
    col = x;
}
/// getter ----------------------------------------------------------

int     matrix::getRow()    { return row;  }        /// return the row value
int     matrix::getCol()    { return col;  }        /// return the col value
int**   matrix::getArray()  { return data; }        /// return pointer of the array

/// operators overloading -------------------------------------------

/// input stream function
istream& operator >> ( istream& in , matrix& mat )
{
    int **arr = mat.getArray();
    for ( int i = 0; i < mat.getRow(); i++ )
    {
        for ( int j = 0; j < mat.getCol(); j++ )
        {
            in >> setw(5) >> arr[i][j];
        }

    }
    return in ;
}

/** delete this line and write the functions here **/

/// output stream function
ostream& operator<< ( ostream& out , matrix& mat )
{
    int **arr = mat.getArray();
    for ( int i = 0; i < mat.getRow(); i++ )
    {
        for ( int j = 0; j < mat.getCol(); j++ )
        {
            out << setw(5) << arr[i][j];
        }
        out << endl;
    }
    return out;
}

/** Write the 2 types of the (+,-,*) operators **/
matrix* matrix :: operator+  ( matrix& mat )
{
    if ( this->row == mat.row && this->col == mat.col)
    {
        matrix* newMat = new matrix(this->row, this->col);
        for ( int i = 0; i < this->row; i++ )
        {
            for ( int j = 0; j < this->col; j++)
                newMat->data[i][j] = this->data[i][j] + mat.data[i][j];
        }
        return newMat;
    }
    else
        cout << " enter two matrices in the same size " << endl ;

    return this;
}

matrix* matrix :: operator-  ( matrix& mat)
{
    if ( this->row == mat.row && this->col == mat.col)
    {
        matrix* newMat = new matrix(this->row, this->col);
        for ( int i = 0; i < this->row; i++ )
        {
            for ( int j = 0; j < this->col; j++)
                newMat->data[i][j] = this->data[i][j] - mat.data [i][j];
        }
        return newMat;
    }
    else
        cout << " enter two matrices in the same size " << endl ;

    return this;
}

matrix* matrix :: operator*  ( matrix& mat)
{
    if ( this->col == mat.row )
    {
        matrix* newMat = new matrix(this->row, this->col);
        for ( int i = 0; i < this->row; i++ )
        {
            for ( int j = 0; j <mat.col; j++ )
            {
                int sum = 0;
                for ( int k = 0; k < mat.row; k++ )
                {
                    sum += this->data[i][k] * mat.data[k][j];
                }
                newMat->data[i][j] = sum;
            }
        }
        return newMat ;
    }
    return this;
}

matrix* matrix :: operator+  ( int scalar )
{
    matrix* newMat = new matrix(this->row, this->col);
    for ( int i = 0; i < this->row; i++ )
    {
        for ( int j = 0; j < this->col; j++ )
            newMat->data[i][j] = this->data[i][j] + scalar;
    }

    return newMat;
}

matrix* matrix :: operator-  ( int scalar )
{
    matrix* newMat = new matrix(this->row, this->col);
    for ( int i = 0; i < this->row; i++ )
    {
        for ( int j = 0; j < this->col; j++ )
            newMat->data[i][j] = this->data[i][j] - scalar;
    }

    return newMat;
}

matrix* matrix :: operator*  ( int scalar )
{
    matrix* newMat = new matrix(this->row, this->col);
    for ( int i = 0; i < this->row; i++ )
    {
        for ( int j = 0; j < this->col; j++ )
            newMat->data[i][j] = this->data[i][j] * scalar;
    }
    return newMat;
}

/** delete this line and write the functions here **/


/** the 2 types of the ( += , -= , ++ , -- ) operators **/
matrix* matrix::operator += ( matrix& mat )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] += mat.data[i][j];

    return this;
}
matrix* matrix::operator -= ( matrix& mat )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] -= mat.data[i][j];

    return this;
}
matrix* matrix::operator += ( int value  )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] += value;

    return this;
}
matrix* matrix::operator -= ( int value  )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] -= value;

    return this;
}

void    matrix::operator ++ (  )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j]++;


}
void    matrix::operator -- (  )
{
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j]--;
}

matrix* matrix::operator ++ ( int )
{
    matrix* ptr = new matrix( *this );
    ++(*this);

    return ptr;
}
matrix* matrix::operator -- ( int )
{
    matrix* ptr = new matrix( *this );
    --(*this);

    return ptr;
}

/** the equality functions **/
bool matrix::operator==(matrix& mat2)
{ //check if the first matrix equals the second matrix, if yes then return true
    if ( this->col == mat2.col && this->row == mat2.row ) //check if same size
    {
        int check = 0; // assume they are equal (true)
        for (int i = 0; i < this->row; i++ )
        {
            for ( int j = 0; j < this->col; j++ )
            {//loop through all elements of the matrix
                if ( this->data[i][j] != mat2.data[i][j] )
                {
                    check++ ;// add 1 to the check integer in order to make it more than zero
                }
            }
        }
        if ( check == 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool matrix::operator!=(matrix& mat2)
{ //check if the first matrix doesnt equals the second matrix, if yes then return true
    if (*this == mat2)
    {
        return false;
    }
    else
    {
        return true;
    }
}


bool matrix::isSquare()// if matrix is square with same rows and same columns then return true
{
    if ( this->col == this->row )//checks if rows equals columns
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool matrix::isSymetric()//symmetric matrix is a square matrix that is equal to its transpose.
{
    if ( this->isSquare() )//checks if matrix is square
    {
        this->transpose();
        matrix test(*this);
        this->transpose();
        if (*this == test)//checks if matrix is equal to its transpose
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}


bool matrix::isIdentity()//identity matrix is a square matrix with all main diagonal ones and the rest is zero
{
    if ( this->isSquare() )//checks if square
    {
        for ( int i = 0; i < this->row; i++ )
        {
            for ( int j = 0; j < this->col; j++)//loops through the whole matrix
            {
                if( i == j )
                {
                    if ( this->data[i][j] != 1 )//checks that main diagonal is all ones
                    {
                        return false;
                    }
                }
                if ( i != j )
                {
                    if ( this->data[i][j]!= 0 )//checks that all the other elements are zeros
                    {
                        return false;
                    }
                }
            }

        }
        return true;
    }
    else
    {
        return false;
    }
}


void matrix::transpose()//changes rows into columns and columns into rows
{
    int data_temp[] = {};
    matrix  trans(this->col, this->row);//the transposed matrix
    for ( int i = 0; i < this->col; i++ )
    {
        for ( int j = 0; j < this->row; j++ )
        {
            trans.data[i][j] = this->data[j][i];
        }
    }

    matrix tempp(trans);
    this->row = tempp.row;
    this->col = tempp.col;

    this->~matrix(); //destructs matrix to create new matrix

    this->data = new int*[ this->row ]; //creates new transposed matrix
    for ( int i = 0; i < this->row; i++ )
        this->data[ i ] = new int [ this-> col ];

    int** a = tempp.getArray();
    for ( int i = 0; i < this->row; i++ )
        for ( int j = 0; j < this->col; j++ )
            this->data[i][j] = a[i][j];
}

/// destructor ------------------------------------------------------
matrix::~matrix()
{
    for ( int i = 0; i < this->col; i++ ) delete[] this->data[ i ];
    delete[] this->data;
}


