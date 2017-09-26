#include <iostream>
#include <cmath>
using namespace std;

bool Prim ( int x );

int main()
{
    int a, b, minim = 0x3f3f3f3f, x;
    cin >> a >> b;
    for ( int i = a; i <= b; ++i )
        if ( Prim(i))
        {
            int m = abs(b+a-2*i);
            if ( m < minim )
            {
                minim = m;
                x = i;
            }
        }
    if ( minim == 0x3f3f3f3f )
        cout << 0;
    else
        cout << x;
    return 0;
}

bool Prim ( int x )
{
    if ( x == 0 || x == 1 )
        return false;
    if ( x == 2 )
        return true;
    if ( x % 2 == 0 )
        return false;
    for (int d = 3; d * d <= x; d += 2 )
        if ( x % d == 0 )
            return false;
    return true;
}
