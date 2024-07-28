#include "CFabric.h"

int CComplexVector0::output()
{
    FILE* f;
    f = fopen(fl.c_str(), "a");
    for (int i = 0; i < N; i++)
        if (x[i].Im() < 0)
            fprintf(f, "%.2lf - %.2lfi; ", x[i].Re(), -1 * x[i].Im());
        else
            fprintf(f, "%.2lf + %.2lfi; ", x[i].Re(), x[i].Im()); //z = x  iy

    fprintf(f, "\n----------\n");
    fclose(f);
    return 0;
}


int CComplexVector1::output()
{
    FILE* f;
    f = fopen(fl.c_str(), "a");
    for (int i = 0; i < N; i++)
        if (x[i].Im() < 0)
            fprintf(f, "%.2lf - %.2lfi;\n", x[i].Re(), -1 * x[i].Im());
        else
            fprintf(f, "%.2lf + %.2lfi;\n", x[i].Re(), x[i].Im());

    fprintf(f, "----------\n");
    fclose(f);
    return 0;
}

                                                  
