//Nodea Eugen
# include <fstream>
using namespace std;

ifstream f("triunghi.in");
ofstream g("triunghi.out");

long long a[1001][1001];
long long i, n, j, k, v[1001], p[1001];
int main()
{
    f>>n;
    for (i=n; i>0; --i)
    {
        f>>p[i]>>v[i];
    }
    a[1][1]=v[1];
    for (i=2; i<=n; ++i)
        {
            //refac linia i
            j=p[i];
            a[i][j]=(long long)v[i];
            //refac stanga
            k=j-1;
            while (k)
            {
                a[i][k]=a[i-1][k]-a[i][k+1];
                --k;
            }
            //refac dreapta
            k=j+1;
            while (k<=i)
            {
                a[i][k]=a[i-1][k-1]-a[i][k-1];
                ++k;
            }
        }
    for (j=1; j<n; ++j)
        g<<a[n][j]<<' ';
    g<<a[n][n]<<'\n';

    return 0;
}
