#include<iostream>
using namespace std;

int putere(int ) ;

int main()
{
    int a , s = 0  ;
    cin >> a;
    while (a !=0 )
    {

        s += putere(a);
        --a;

    }
    cout << s;
    return 0;
}

int putere(int x)
{
    int p = 1;
     for (int i = 1; i <= x; ++i )
        {
            p = p * x;
        }
    return p;
}
