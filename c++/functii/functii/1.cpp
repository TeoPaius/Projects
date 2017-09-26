// MECANISMUL de Transfer "Prin VALOARE"
#include <iostream>
using namespace std;

// a, b - PARAMETRI FORMALI

int Suma(int a, int b); // PROTOTIPUL functiei

int main()
{
    int x, y;
    cin >> x >> y;
    cout << Suma(x, y) << '\n'; // APELUL
    // x, y = argumentele functiei
    cout << Suma(12, 89);
    return 0;
}

int Suma(int a, int b)
{
    return a + b;
}
