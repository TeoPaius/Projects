/*  Rucsac de capacitate G.
    n tipuri de obiecte de greutati g[1], ..., g[n]
    Sa se gaseasca greutatea maxima care poate fi introdusa in rucsac.
    Fiecare obiect poate fi folosit o singura data.
    Sa se foloseasca un numar minim de obiecte din sirul g
*/
#include <fstream>
using namespace std;

#define Inf 0x3f3f3f3f

ifstream is("rucs1.in");
ofstream os("rucs1.out");

int n, G, g[100];
int c[1000];
int t[1000];
void Write(int g);

int main()
{
    is >> n >> G;
    for ( int i = 1;i <= n; ++i )
        is >> g[i];

    for(int i = 1; i <= G; ++i)
        c[i] = Inf;
    c[0] = 0;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 0; j <= G - g[i]; ++j )
            if ( c[j] != Inf && c[j + g[i]] > c[j] + 1)
            {
                c[j + g[i]] = c[j] + 1;
                t[j + g[i]] = i;
            }
    for ( int i = G; i; --i )
        if ( c[i] != Inf )
        {
            os << i << '\n';
            Write(i);
            break;
        }
    is.close();
    os.close();
    return 0;
}

void Write(int gr)
{
    if ( !gr ) return;
    Write(gr - g[t[gr]]);
    os << g[t[gr]] << ' ';
}
