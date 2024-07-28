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
#include "head.h"

using namespace std;

class CComplex
{
public:
    double re, im;

    CComplex()
    {
        re = 0;
        im = 0;
    }

    CComplex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    double Re() const
    {
        return re;
    }

    double Im() const
    {
        return im;
    }

    void print() const
    {
        if (im < 0)
            printf("%.2lf - %.2lfi", re, -1 * im);
        else
            printf("%.2lf + %.2lfi", re, im);;
    }



    CComplex operator*(const CComplex& b);
    CComplex operator-(const CComplex& b);
    CComplex operator+(const CComplex& b);
    friend ostream& operator<<(ostream& cout, const CComplex& x);
};
