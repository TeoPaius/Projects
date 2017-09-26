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


void F(Bancnota b) // apelul construcorului
{                  // de copiere
}

void G(const Bancnota& b)
{
}

int main()
{
    Bancnota b1(100);
    Bancnota b2(b1); // Bancnota(b1)
  //  F(b1);
 //   G(b1);

    return 0;
}
