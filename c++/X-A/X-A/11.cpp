// Constructor de copiere (copy contructor)
#include <iostream>
using namespace std;

class Bancnota {
    int valoare;
public:
    Bancnota(int v = 10)
        : valoare(v)
    {
        cout << "Construiesc bancnota "
             << valoare << '\n';
    }

    Bancnota(const Bancnota& b)
    {
        valoare = b.valoare;
        cout << "Construiesc prin copiere  bancnota"
             << valoare << '\n';
    }
    ~Bancnota()
    {
        cout << "Distrug bancnota " << valoare << '\n';
    }
};

int main()
{
    Bancnota b1(100);
    Bancnota b2 = b1; // copiere
    Bancnota b3(b2);  // copiere

    return 0;
}
