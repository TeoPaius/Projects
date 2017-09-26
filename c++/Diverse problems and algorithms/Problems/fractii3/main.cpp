#include <iostream>
#include <fstream>
using namespace std;
ifstream is ("fractii.in");
ofstream os ("fractii.out");
long n;

int main(int argc, char** argv) {
    is>> n;
    int numere[n+1];
    for (int i=1;i<=n;i++)
        numere[i]=n;
    bool multiplii[n+1];
    for (int i=2;i<=n/2;i++)
        for (int j=2;j<=n/i;j++)
        multiplii[i*j]=true;

    for (int i=2;i<=n;i++)
        if(multiplii[i]==false)
            for (int j=1;j<=n/i;j++)
                numere[j*i]=numere[i*j]-n/i;

        int cite=0;
        for (int i=1;i<=n;i++)
            cite=cite+numere[i];
        os<<cite;
    return 0;
}
