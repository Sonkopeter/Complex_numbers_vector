#include "CComplex.h"

CComplex CComplex::operator-(const CComplex& b)
{
    CComplex r(re - b.Re(), im - b.Im());
    return r;
}


CComplex CComplex::operator*(const CComplex& b)
{
    CComplex r(re * b.Re() - im * b.Im(), im * b.Re() + re * b.Im());
    return r;
}

CComplex CComplex::operator+(const CComplex& b)
{
    CComplex r(re + b.Re(), im + b.Im());
    return r;
}
