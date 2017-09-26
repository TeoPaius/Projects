#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[] = "Am mers afara ";
    char b[] = "dupa placinta";

    strcat(a, b);
    cout << a;

    return 0;
}
