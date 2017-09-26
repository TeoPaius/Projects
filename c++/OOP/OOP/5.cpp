
#include <iostream>
using namespace std;

class Intreg {
    int n;
public:
    Intreg(int _n = 0) // c-tor cu parametru care are val implicita
    {
        n = _n;
    }
    int GetN()
    {
        return n;
    }
};

int main()
{
    Intreg x; // Intreg(0)
    cout << x.GetN() << '\n';

    Intreg y(100); // Apel Implicit Intreg(100)
    cout << y.GetN();
    Intreg z = Intreg(200); // Apel Explicit Intreg(100)

    return 0;
}

