/*  Rucsac de capacitate G.
    n tipuri de obiecte de greutati g[1], ..., g[n]
    Sa se gaseasca greutatea maxima care poate fi introdusa in rucsac.
    Fiecare obiect poate fi folosit de mai multe ori.
*/
#include <fstream>
using namespace std;

ifstream is("rucs1.in");
ofstream os("rucs1.out");

int n, G, g[100];
bool OK[1000];
int t[1000];
void Write(int g);

int main()
{
    is >> n >> G;
    for ( int i = 1;i <= n; ++i )
        is >> g[i];
    OK[0] = true;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 0; j <= G - g[i]; ++j )
            if ( OK[j] )
            {
                OK[j + g[i]] = true;
                t[j + g[i]] = i;
            }
    for ( int i = G; i; --i )
        if ( OK[i] )
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
