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
    ~Bancnota()
    {
        cout << "Distrug bancnota " << valoare << '\n';
    }
};

int main()
{
    Bancnota b1(100);
    Bancnota b2 = b1;
    // b2 se construieste prin copiere din b1
    // copiere bit cu bit (bitwise copy)
    // Echivalent cu:
    // Bancnota b2 = Bancnota(b1);
    return 0;
}
