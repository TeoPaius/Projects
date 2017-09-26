#include <iostream>
#include <fstream>
using namespace std;
ifstream is ("sahara.in");
ofstream os ("sahara.out");

char x[100];
char y[100];
char z[100];
int u;

int a,b ,c;

int main()
{
    c = 1;
    cin >> a >> b;

    while(b>0)
    {
        if(b%2 == 1)
            c = (a*c)%10;
        a = (a*a)%10;
        b/=2;
    }
    cout << c;
    return 0;
}
