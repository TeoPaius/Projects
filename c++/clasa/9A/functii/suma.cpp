#include<iostream>
using namespace std;

int suma (int x, int y);

int main()
{
   int a, b;
   cin >> a >> b;
   cout << suma(a, b);

    return 0;
}


int suma (int x, int y)
{
    return x+y;
}
