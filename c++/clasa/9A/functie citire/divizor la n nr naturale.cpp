#include<fstream>
using namespace std;

ifstream is ("divizor la n nr naturale.in");
ofstream os ("divizor la n nr naturale.out");
int cmmdc( int a, int b);

int main ()
{
    int n, i, d, x;
    is >> n;
    is >> d;
    for(i = 0; i < n - 1; ++i)
    {
     is >> x;
     d = cmmdc(d, x);
    }
    os << d << '\n';

    is.close();
    os.close();
}
int cmmdc (int a, int b)
{
    if( a == 0)
        return b;
    if ( b == 0)
        return a;

    while ( a != b)
        if(a < b)
            b -= a;
        else
            a -=b;
    return a;
}

