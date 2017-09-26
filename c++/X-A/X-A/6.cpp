// Ordinea construirii si distrugerii obiectelor
#include <iostream>
using namespace std;

class Copil {
    string nume;
public:
    Copil(string num = "Ioana")
       : nume(num)
    {
        cout << "Construiesc " << nume << '\n';
    }
    ~Copil()
    {
        cout << "Distrug " << nume << '\n';
    }
};

Copil a("Gina"), b("Denisa");

int main()
{
    cout << "Prima instructiune din main()\n";

    Copil c1, c2("Ion");

    cout << "Ultima instructiune din main\n";
    return 0;
}
