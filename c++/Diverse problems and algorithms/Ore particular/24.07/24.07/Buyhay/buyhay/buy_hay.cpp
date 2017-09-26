/*  Rucsac de capacitate G.
    n tipuri de obiecte de greutati g[1], ..., g[n]
    Sa se gaseasca greutatea maxima care poate fi introdusa in rucsac.
    Fiecare obiect poate fi folosit o singura data.
    Sa se foloseasca un numar minim de obiecte din sirul g
*/
#include <fstream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("buyhay.10.in");
ofstream os("buy_hay.out");

int n, G;
int g[101], p[101];
int v[55002];

int main()
{
    is >> n >> G;
    for ( int i = 1; i <= n; ++i )
        is >> g[i] >> p[i];

    for ( int i = 1; i <= G + 5001; ++i )
        v[i] = INF;
    v[0] = 0;
    int MAXIM = -1;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 0; j <= G; ++j )
            if ( v[j] != INF && v[j + g[i]] > v[j] + p[i] )
            {
                v[j + g[i]] = v[j] + p[i];
                MAXIM = max(MAXIM, j + g[i]);
            }
    int MINIM = INF;
    for ( int i = G; i <= MAXIM; ++i )
        if ( v[i] != INF )
        {
            MINIM = min(MINIM, v[i]);
        }
    os << MINIM;

    is.close();
    os.close();
    return 0;
}
