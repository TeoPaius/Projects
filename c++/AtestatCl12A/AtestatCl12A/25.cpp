#include <fstream>
using namespace std;

ifstream is("numere.in");
ofstream os("numere.out");

int a[10000], x;

int main()
{
    while ( is >> x )
        a[x] = 1;
    for ( int i = 9999; i >= 1; --i )
        if ( a[i] == 0)
            os << i << ' ';
    is.close();
    os.close();
    return 0;
}
