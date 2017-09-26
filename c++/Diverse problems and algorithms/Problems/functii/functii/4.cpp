// MECANISMUL de Transfer "Prin REFERINTA"
#include <iostream>
using namespace std;

int Cmmdc(int a, int b);
void Cmmdc(int a, int b, int& d);

int main()
{
    int x, y;
    cin >> x >> y;
    //cout << Cmmdc(x, y);
    int cmmdc;
    Cmmdc(x, y, cmmdc);
    cout << cmmdc;
    return 0;
}

void Cmmdc(int a, int b, int& d)
{
    if ( a == 0 )
    {
        d = b;
        return;
    }
    if ( b == 0 )
    {
       d = a;
       return;
    }
    while ( a != b)
        if ( a > b )
            a -= b;
        else
            b -= a;
    d = a;
}
int Cmmdc(int a, int b)
{
    if ( a == 0 ) return b;
    if ( b == 0 ) return a;
    while ( a != b)
        if ( a > b )
            a -= b;
        else
            b -= a;
    return a;
}
