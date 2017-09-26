#include <fstream>
#include <cstring>
using namespace std;

ifstream is("numere.in");
ofstream os("numere.out");

int main()
{
    int n,m, a[100], b[100];
    is >> n >> m;
    for(int i=1; i<=n; i++)
        is >> a[i];
    for(int j=1; j<=m; j++)
        is >> b[j];

    int j=1;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==b[j]) j++;
    }

    if(j-1==m)
        os<<"se poate";
    else
        os<<"nu se poate";
    return 0;
}

