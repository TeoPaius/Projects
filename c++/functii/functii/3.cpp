// MECANISMUL de Transfer "Prin REFERINTA"
#include <iostream>
using namespace std;

void Swap(int& a, int& b);

int main()
{
    int x, y;
    cin >> x >> y;
    Swap(x, y);
    cout << x << ' ' << y;
    return 0;
}

void Swap(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}
