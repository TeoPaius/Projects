/*Se citeste un numar natural n apoi inca n numere naturale.
Sã se afiseze acele numere ce au proprietatea de palindrom. */
#include<fstream>
using namespace std;

ifstream is ("palindrom.in");
ofstream os ("palindrom functie.out");

bool Palindrom( int x );

int main()
{
    int n;
    int v;
    is >> n;
    for(int i = 0; i < n; ++i)
    {
        is >> v;
        if( Palindrom(v) )
            os << v << ' ';
    }
    is.close();
    os.close();

    return 0;
}

bool Palindrom( int x )
{
    int inv = 0;
    int y = x;
    for( ; x; x /= 10 )
    {
        inv = inv * 10 + x % 10;
    }
    if ( inv == y)
        return true;
    return false;
}
