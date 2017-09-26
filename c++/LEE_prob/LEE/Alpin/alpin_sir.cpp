#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

#define Nmax 1025
#define INF 16385

ifstream fin("alpin.in");
ofstream fout("alpin.out");

struct Cell {
    int i;
    int j;
    int v;
} c[Nmax*Nmax];

bool OK ( int , int );
void Drum ( int );
bool Comp ( const Cell&, const Cell& );

int a[Nmax][Nmax];
int n;
int Lmax, imax, jmax;
int d[Nmax*Nmax];
int t[Nmax*Nmax];
int D[Nmax][Nmax];

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

int main()
{
    fin >> n;
    int q = 1;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            fin >> a[i][j];
            c[q].i = i;
            c[q].j = j;
            c[q].v = a[i][j];
            ++q;
        }
    sort ( c + 1, c + 1 + n*n, Comp );
    int i, j;
    for ( int k = 1; k <= n*n; ++k )
    {
        i = c[k].i;
        j = c[k].j;
        D[i][j] = k;
    }
    int iv, jv;
    for ( int i = 1; i <= n*n; ++i )
    {
        d[i] = 1;
        for ( int k = 0; k < 4; ++k )
        {
            iv = c[i].i + di[k];
            jv = c[i].j + dj[k];
            j = D[iv][jv];
            if ( j < i && d[j] + 1 > d[i] )
            {
                d[i] = d[j] + 1;
                t[i] = j;
            }
        }
    }
    for ( int i = 1; i <= n*n; ++i )
        if ( d[i] > Lmax )
        {
            Lmax = d[i];
            imax = i;
        }
    fout << Lmax << '\n';
    //fout << c[imax].i + 1 << ' ' << c[imax].j + 1 << '\n';
    Drum ( imax );
    fin.close();
    fout.close();
    return 0;
}

void Drum ( int i )
{
    if ( !i )
        return;
    Drum ( t[i] );
    fout << c[i].i << ' ' << c[i].j << '\n';
}

bool Comp ( const Cell& c1 , const Cell& c2 )
{
    return c1.v <= c2.v;
}
