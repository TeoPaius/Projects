#include <fstream>
using namespace std;

ifstream is("hercule.in");
ofstream os("hercule.out");

struct ceva{
    int ii, jj;
}drum[40005];

int di[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1};
int m, n;
int matrice[201][201];
int cadere[201][201];
int i1, j1, i2, j2;
int contor = 1;

int main()
{
    is >> m >> n;
    for ( int i = 1; i <= m; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            is >> cadere[i][j];

        }
    is >> i1 >> j1 >> i2 >> j2;
    matrice[i1][j1] = 1;
    contor = 1;
    int timp = 0;
    bool modificat;
    int iv, jv;
    while ( modificat )
    {
        modificat = false;
        for ( int i = 1; i <= m; ++i )
            for ( int j = 1; j <= n; ++j )
            {
                if ( contor == matrice[i][j] )
                for ( int k = 1; k <= 8; ++k )
                {
                    iv = i + di[k];
                    jv = j + dj[k];
                    if ( timp < cadere[iv][jv] && !matrice[iv][jv] )
                    {
                        modificat = true;
                        matrice[iv][jv] = contor + 1;
                    }
                }
            }
        ++timp;
        ++contor;
    }
    --timp;
    os << timp << "\n";




    is.close();
    os.close();
    return 0;
}

/*
#include <fstream>
using namespace std;

ifstream is("hercule.in");
ofstream os("hercule.out");

struct ceva{
    int ii, jj;
    int timp;
}cadere[40005], aux;

int m, n;
int matrice[201][201];
int i1, j1, i2, j2;
int contor = 1;

int main()
{
    is >> m >> n;
    for ( int i = 1; i <= m; ++i )
        for ( int j = 1; j <= n; ++j )
        {
            cadere[contor].ii = i;
            cadere[contor].jj = j;
            is >> cadere[contor].timp;
        }
    is >> i1 >> j1 >> i2 >> j2;
    for ( int i = 1; i <= m; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( cadere[i].timp > cadere[j].timp )
            {
                aux = cadere[i];
                cadere[i] = cadere[j];
                cadere[j] = aux;
            }
    matrice[i1][j1] = 1;
    is.close();
    os.close();
    return 0;
}

*/
