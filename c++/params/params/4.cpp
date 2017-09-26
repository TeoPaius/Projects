#include <iostream>
using namespace std;

int main()
{
    int a = 100;
//    cout << &a;  // operator adresa
    int* p;    // declar un pointer la int
    p = &a;
    cout << p;
    cout << '\n';
    *p = 2000;   // operator de dereferire
                 // sau de dereferentiere
    cout << *p << ' ' << a;

    return 0;
}
