#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int a;
string b;
char c[100];

int main()
{
    cin >> a;
    //b = to_string(a);
     itoa(a,c,10);
    cout << c[0];

    return 0;



}
