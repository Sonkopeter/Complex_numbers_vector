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
#include "CComplex.h"

using namespace std;

class CComplexVector
{
public:
    CComplex* x;
    int N;

    void Clean()
    {
        delete[] x;
        SetZero();
    }

    void SetZero()
    {
        x = NULL;
        N = 0;
    }

    void CopyOnly(const CComplexVector& b)
    {
        N = b.N;
        memcpy(x = new CComplex[N], b.x, b.N * sizeof(*x));
    }

    CComplexVector()
    {
        SetZero();
    }

    CComplexVector(double* a, double* b, int N)
    {
        this->N = N;
        x = new CComplex[N];
        for (int i = 0; i < N; i++)
            x[i] = CComplex(a[i], b[i]);
    }

    CComplexVector(const CComplex* v, int N)
    {
        x = new CComplex[N];
        this->N = N;
        for (int i = 0; i < N; i++)
        {
            x[i] = v[i];
        }
    }

    CComplexVector(int N)
    {
        int i;
        this->N = N;
        x = new CComplex[N];
        for (i = 0; i < N; i++)
            x[i] = CComplex();
    }


    CComplexVector(const CComplexVector& y)
    {
        (*this).CopyOnly(y);
    }

    virtual ~CComplexVector()
    {
        Clean();
    }

    virtual int output() = 0;

    CComplexVector& operator=(const CComplexVector& b)
    {
        if (this != &b)
        {
            Clean();
            N = b.N;
            (*this).CopyOnly(b);
        }
        return *this;
    }

    void print() const
    {
        printf("(");
        for (int i = 0; i < N; i++)
        {
            x[i].print();
            if (i != N - 1)
                printf(", ");
        }
        printf(")");
    }

    void Resize(int);
    CComplex& operator[](int);
    static int Input(char*, vector<CComplexVector*>& a, vector<CFabric*>& fabric);
    CComplex operator*(const CComplexVector& b) const;
    friend ostream& operator<<(ostream& cout, const CComplexVector& x);
};

