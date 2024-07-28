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
#include "CComplexVector01.h"
#include "head.h"

using namespace std;

class CFabric  //виртуальный
{
public:
    virtual CComplexVector* Create() = 0;
    virtual CComplexVector* Create(string fl) = 0;
    virtual ~CFabric() {}
};

class CFabric0 : public CFabric
{
public:
    virtual CComplexVector* Create()
    {
        return new CComplexVector0;
    };
    virtual CComplexVector* Create(string fl)
    {
        return new CComplexVector0(fl);
    };
    virtual ~CFabric0() {}
};

class CFabric1 : public CFabric
{
public:
    virtual CComplexVector* Create()
    {
        return new CComplexVector1;
    };
    virtual CComplexVector* Create(string fl)
    {
        return new CComplexVector1(fl);
    };
    virtual ~CFabric1() {}
};