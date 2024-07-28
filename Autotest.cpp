#include "CFabric.h"
#include "head.h"


int autotest()
{
    double a1[] = { 1, 1 };
    double a2[] = { 2, 5 };
    CComplexVector1 z(a1, a2, 2);
    double b1[] = { 1, 1 };
    double b2[] = { 5, 7 };
    CComplexVector1 w(b1, b2, 2);
    CComplexVector0 resPlus, resMin;
    CComplex resSkal;


   /* CComplex* a, * b;
    double u, v;
    int i, N = 2;

    a = new CComplex[N];
    b = new CComplex[N];

    double c1[] = { 0, 0 };
    double c2[] = { 0, 0 };
    CComplexVector0 rez(c1, c2, 2);

    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        u = -10 + rand() % 20;
        v = -10 + rand() % 20;
        a[i] = CComplex(u, v);
    }

    for (i = 0; i < N; i++)
    {
        u = -10 + rand() % 20;
        v = -10 + rand() % 20;
        b[i] = CComplex(u, v);
    }*/

    //CComplexVector0 z(a, N), w(b, N), resPlus, resMin;
    resPlus = z + w;
    resMin = z - w;
    resSkal = z * w;
    cout << "Z: " << z << endl;
    cout << "W: " << w << endl;
    cout << "Z + W: " << resPlus << endl;

    if ((fabs(resPlus.x[0].re - 2.0) < DBL_EPSILON) && (fabs(resPlus.x[0].im - 7.0) < DBL_EPSILON) && (fabs(resPlus.x[1].re - 2.0) < DBL_EPSILON) && (fabs(resPlus.x[1].im - 12.0) < DBL_EPSILON)) {
        cout << "Test 1 passed" << endl;

    }
    else {
        cout << "Wrong plus" << endl;
        return 0;
    }

    cout << "Z - W: " << resMin << endl;

    if ((fabs(resMin.x[0].re) < DBL_EPSILON) && (fabs(resMin.x[0].im + 3.0) < DBL_EPSILON) && (fabs(resMin.x[1].re) < DBL_EPSILON) && (fabs(resMin.x[1].im + 2) < DBL_EPSILON)) {
        cout << "Test 2 passed" << endl;
    }
    else {
        cout << "Wrong minus" << endl;
        return 0;
    }

    cout << "(Z, W): " << z * w << endl;

    if ((fabs(resSkal.re + 43.0) < DBL_EPSILON) && (fabs(resSkal.im - 19.0) < DBL_EPSILON)) {
        cout << "Test 3 passed" << endl;
    }
    else {
        cout << "Wrong product" << endl;
        return 0;
    }

    return 1;
}
