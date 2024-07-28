#include "CFabric.h"

ostream& operator<<(ostream& cout, const CComplex& x) {
    x.print();
    return cout;
}


ostream& operator<<(ostream& cout, const CComplexVector& x) {
    x.print();
    return cout;
}



int main(void)
{
    char name[64];
    int n, i;
    vector <CComplexVector*> a;
    autotest();
    cout << "Enter your file\n";
    cin >> name;

    FILE* f = fopen(name, "r");

    if (f == NULL)
    {
        printf("File is absent\n");
        return -1;
    }
    fclose(f);

    vector<CFabric*> fabric;

    fabric.push_back(new CFabric0);
    fabric.push_back(new CFabric1);

    n = CComplexVector::Input(name, a, fabric);

    for (i = 0; i < n; i++)
        a[i]->output();

    for (i = 0; i < n; i++)
        delete a[i];

    delete fabric[0];
    delete fabric[1];

    /*double a1[] = {1, 1};
    double a2[] = {2, 5};
    CComplexVector1 aa(a1, a2, 2);
    double b1[] = {1, 1};
    double b2[] = {5, 7};
    CComplexVector1 bb(b1, b2, 2);
    std::string cc_filename = "cc.txt";
    CComplexVector0 cc(cc_filename);
    cc = aa + bb;
    cc.output();*/
    return 0;
}
