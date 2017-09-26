#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

int v[15];

int main()
{
    int S, n, e;
    fin >> S >> n >> e;
    v[0] = 1;
    for(int i = 1 ; i <= n ; i ++)
        v[i] = v[i-1] * e;
    int nrb = 0;
    for(int i = n ; i >= 0 ; i --)
        if(S>= v[i])
        {
            int x = S/v[i];
            fout << v[i] << " " << x << endl;
            nrb = nrb + x;
            S -= x * v[i];
        }
    fout << nrb;
    return 0;
}

