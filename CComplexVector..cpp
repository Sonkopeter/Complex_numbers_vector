#include "CFabric.h"


void CComplexVector::Resize(int i)
{
    CComplex* ft;
    int j;
    ft = new CComplex[i + 1];

    for (j = 0; j < N; j++)
        ft[j] = x[j];

    for (j = N; j < i + 1; j++)
        ft[j] = CComplex();

    Clean();

    N = i + 1;

    *this = CComplexVector0(ft, N);
    delete[] ft;
    ft = NULL;
}

CComplex& CComplexVector::operator[](int i)
{
    if (i < N)
        return x[i];
    else
        (*this).Resize(i);
    return x[i];
}

                                         

CComplex CComplexVector::operator*(const CComplexVector& b) const
{
    CComplex r;
    for (int i = 0; i < N; i++)
        r = r + x[i] * b.x[i];
    return r;
}

int CComplexVector::Input(char* name, vector<CComplexVector*>& a, vector<CFabric*>& fabric)
{
    int i, I, n = 0;
    string fl, s;
    FILE* clean;

    ifstream f(name);

    while (getline(f, fl))
        n++;

    ifstream f1(name);

    if (!f1)
    {
        cout << "File is absent!" << endl;
        return 0;
    }


    while (getline(f1, s))
    {
        stringstream str(s);
        str >> I;
        str >> fl;

        istream_iterator<double> x = str;

        clean = fopen(fl.c_str(), "w");
        fclose(clean);

        if (x != istream_iterator<double>() && I < 2)
        {
            CComplexVector* v = fabric[I]->Create(fl);

            i = 0;

            for (; x != istream_iterator<double>(); ++x)
            {
                istream_iterator<double> y = x;
                y++;
                (*v)[i] = CComplex(*x, *y);
                i++;
            }

            a.push_back(v);
        }
    }

    return n;
}

