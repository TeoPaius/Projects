#include <fstream>
using namespace std;

ifstream is ("fazanr.in");
ofstream os ("fazanr.out");
int prima(int x);
int ultima(int x);

int main()
{
    int n, a, b, nea = 0 , i;
    is >> n;
    is >> a;
    for (i = 1; i < n; i++)
    {
        is >> b;
        if (ultima(a) != prima(b))
        nea++;
        a = b;

    }
    os << nea ;
    return 0;
}


int prima(int x)
{
    while( x > 10)
    {
        x /= 10;
    }
    return x;
}

int ultima(int x)
{
    x %= 10;
    return x;
}
