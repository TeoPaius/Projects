#include <iostream>
#include <fstream>
using namespace std;
ifstream is ("fractii.in");
ofstream os ("fractii.out");
long n;
int numere[500][500];

int main(int argc, char** argv) {
    is>> n;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            numere[i][j]=0;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=n/i;j++)
            for (int k=1;k<=n/i;k++)
                numere[i*j][i*k]=1;
   long cite=0;
    for (int i=1;i<=n;i++)
     for (int j=1;j<=n;j++)
            if (numere[i][j]==0)
                cite++;
    os << cite;
    return 0;
}

