#include <fstream>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int n, a, s, rest;
int cnt, r[11];

int main()
{
    is >> n;
    for ( int i = 1; i <= n; ++i )
    {
        is >> a;
        s += a;
    }
    for ( int i = 1; i <= n; ++i )
    {
        r[i] = s + rest;
        rest = r[i] / 10;
        r[i] %= 10;
    }
    if ( rest )
        r[++n] = rest;
    while ( n )
        os << r[n--];
    is.close();
    os.close();
    return 0;
}

