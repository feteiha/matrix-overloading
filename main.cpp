// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 2 - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Matrix operator overloading
// Authors: Hussien Ashraf, Ehap Fawzy, Thomas Waheed
// IDs:     20170093, 20170072, 20170081
// Date:    1 November 2018
// Version: 1.0

#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{
    //freopen( "output.txt" , "w" , stdout );
    int sz = 3;
    matrix* arr[sz];
    arr[0] = new matrix( 2,2 , 1 );
    arr[1] = new matrix( 2,2 , 5 );
    arr[2] = new matrix( 2,2 , 0 );
/*
    int op = 1;
    cout << "<< " << op++ << " >>" << endl;
    cout << *arr[0] << endl << *arr[1] << endl << *arr[2] << endl << endl;

    cout << "<< " << op++ << " >>" << endl;
    *arr[1] += *arr[0];
    cout << *arr[1] << endl;

    cout << "<< " << op++ << " >>" << endl;
    *arr[1] -= *arr[0];
    cout << *arr[1] << endl;

    cout << "<< " << op++ << " >>" << endl;
    *arr[2] += 9;
    cout << *arr[2] << endl;

    cout << "<< " << op++ << " >>" << endl;
    *arr[2] -= 5;
    cout << *arr[2] << endl;

    cout << "<< " << op++ << " >>" << endl;
    ++(*arr[2]);
    cout << *arr[2] << endl;

    cout << "<< " << op++ << " >>" << endl;
    --(*arr[2]);
    --(*arr[2]);
    cout << *arr[2] << endl;

    cout << "<< " << op++ << " >>" << endl;
    cout << *(*arr[2])++ << endl;
    cout <<  *arr[2]    << endl;

    cout << "<< " << op++ << " >>" << endl;
    cout << *(*arr[2])-- << endl;
    cout <<  *arr[2]    << endl;


*/
    for ( int i = 0; i < sz; i++ )
        delete arr[i];
    ///-----------------------------------------------------------------------

    /**-----------------------------------------------------------------------
        Hussien Space Area
    **/
    int data[6]={1,1,1,2,2,2};
    matrix test(2,3,data);

    cout << "False= " << false  << endl <<"True= " << true << endl;
    cout << test.isIdentity()   << endl;
    cout << test.isSquare()     << endl;
    cout << test.isSymetric()   << endl;
    cout << test                << endl;
    test.transpose();
    cout << test                << endl;
    cout << (test == test)      << endl;
    cout << (test!= test)       << endl;
    ///-----------------------------------------------------------------------

    return 0;
}
