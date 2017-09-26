#include <iostream>
using namespace std;

int n;
int cif;
int maxim = -1;

int main()
{
    cin >> n;

    cif = n % 10;
    if(cif % 2 == 0)
        if(maxim < cif)
            maxim = cif;
    n = n / 10;

    cif = n % 10;
    if(cif % 2 == 0)
        if(maxim < cif)
            maxim = cif;
    n = n / 10;

    cif = n % 10;
    if(cif % 2 == 0)
        if(maxim < cif)
            maxim = cif;
    n = n / 10;

    cif = n % 10;
    if(cif % 2 == 0)
        if(maxim < cif)
            maxim = cif;
    n = n / 10;

    cout  << maxim;
}
