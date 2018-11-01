#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class matrix
{
private:
    int** data;
    int row , col;

public:

/// constructor overloaded ------------------------------------------
    matrix( matrix& mat );                      /// copy constructor
    matrix( int row , int col );                /// constructor to allocate the memory and fill with garbage.
    matrix( int row , int col , int value );    /// constructor to allocate the memory and fill with value.
    matrix( int row , int col , int arr[] );    /// constructor to allocate the memory and fill with array values.

/// setter ----------------------------------------------------------
    setRow(int);
    setColomn(int);

/// getter ----------------------------------------------------------

    int     getRow();    /// return the row value
    int     getCol();    /// return the col value
    int**   getArray();  /// return pointer of the array

/// operators overloading -------------------------------------------

     /** the 2 types of the (+,-,*) operators **/
    matrix* operator+  ( matrix& mat);  // Add if same dimensions
    matrix* operator-  ( matrix& mat);  // Sub if same dimensions
    matrix* operator*  ( matrix& mat);  // Multi if col1 == row2
    matrix* operator+  ( int scalar  );  // Add a scalar
    matrix* operator-  ( int scalar  );  // Subtract a scalar
    matrix* operator*  ( int scalar  );  // Multiple by scalar

    /** the 2 types of the ( += , -= , ++ , -- ) operators **/
    matrix* operator += ( matrix& mat );
    matrix* operator -= ( matrix& mat );
    matrix* operator += ( int value   );
    matrix* operator -= ( int value   );

    void    operator ++ (     );
    void    operator -- (     );
    matrix* operator ++ ( int );
    matrix* operator -- ( int );

    /** the equality functions **/
    //Student #3 with the biggest ID
    bool operator== (matrix&);	// True if identical
    bool operator!= (matrix&); 	// True if not same
    bool isSquare ();  // True if square matrix
    bool isSymetric();  // True if square and symmetric
    bool isIdentity();  // True if square and identity
    void transpose();  // Return new matrix with the transpose
    /** Write the functions prototype of the equality functions here **/


/// functions -------------------------------------------------------

/// destructor ------------------------------------------------------
    ~matrix();
};

/// input stream function
/** delete this line and write the prototype of the functions here **/

/// output stream function
ostream& operator << ( ostream& out , matrix& mat );
istream& operator >> ( istream& in , matrix& mat );

#endif // MATRIX_H_INCLUDED
