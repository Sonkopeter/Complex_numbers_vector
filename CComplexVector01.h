#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include "CComplexVector.h"

using namespace std;

class CComplexVector1;

class CComplexVector0 : public CComplexVector
{
public:
    string fl;
    CComplexVector0() : CComplexVector(){}
    CComplexVector0(CComplexVector0 &b) : CComplexVector(){
            if (this != &b)
            {
                Clean();
                N = b.N;
                (*this).CopyOnly(b);
            }
        }

    CComplexVector0(int N) : CComplexVector(N) {}
    CComplexVector0(CComplex* a, int N) : CComplexVector(a, N) {}
    CComplexVector0(double* a, double* b, int N) : CComplexVector(a, b, N) {}
    CComplexVector0(string& fl)
    {
        x = NULL;
        N = 0;
        this->fl = fl;
    }

    int output();
    CComplexVector0& operator=(const CComplexVector0& b)
    {
        if (this != &b)
        {
            Clean();
            N = b.N;
            (*this).CopyOnly(b);
        }
        return *this;
    }



friend CComplexVector0 operator+(const CComplexVector& a, const CComplexVector& b)
{
    CComplexVector0 r(a.N);
    for (int i = 0; i < a.N; i++)
        r.x[i] = a.x[i] + b.x[i];
    return r;
}

friend CComplexVector0 operator-(const CComplexVector& a, const CComplexVector& b)
{
    CComplexVector0 r(a.N);
    for (int i = 0; i < a.N; i++)
        r.x[i] = a.x[i] - b.x[i];
    return r;
}
};

CComplexVector0 operator+(const CComplexVector& a, const CComplexVector& b) ;
CComplexVector0 operator-(const CComplexVector& a, const CComplexVector& b) ;

class CComplexVector1 : public CComplexVector
{
public:
    string fl;
    CComplexVector1() : CComplexVector() {}
    CComplexVector1(int N) : CComplexVector(N) {}
    CComplexVector1(CComplex* a, int N) : CComplexVector(a, N) {}
    CComplexVector1(double* a, double* b, int N) : CComplexVector(a, b, N) {}
    CComplexVector1(string& fl)
    {
        x = NULL;
        N = 0;
        this->fl = fl;
    }

    int output();
    CComplexVector1& operator=(const CComplexVector1& b)
    {
        if (this != &b)
        {
            Clean();
            N = b.N;
            (*this).CopyOnly(b);
        }
        return *this;
    }

    CComplexVector1& operator=(const CComplexVector0& b)
    {
            Clean();
            N = b.N;
            (*this).CopyOnly(b);
 
        return *this;
    }

};

