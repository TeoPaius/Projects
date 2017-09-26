#include <fstream>
using namespace std;

ifstream is ("paianjen.in");
ofstream os ("paianjen.out");

int a, b, n;
int x;
int y;


int main()
{
    is >> x >> y;
    a = 1;
    for ( int i = 2; i <= x; ++i )
        a *= i;
    b = 1;
    for ( int i = 2; i <= y; ++i )
        b *= i;
    n = a;
    for ( int i = x + 1; i <= x + y; ++i )
        n *= i;
    os << n / ( a * b );
    is.close();
    os.close();
    return 0;
}



/*
#include <fstream>
using namespace std;

ifstream is ("paianjen.in");
ofstream os ("paianjen.out");

int a[81][81];
int x;
int y;


int main()
{
    is >> x >> y;
    for(int i = 0; i <= x; ++i)
        a[i][0] = 1;
    for(int j = 0; j <= y; ++j)
        a[0][j] = 1;
    for(int i = 1; i <= x; ++i)
        for(int j = 1; j <= y; ++j)
        {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    os << a[x][y];
    is.close();
    os.close();
    return 0;
}*/

