// Lista de initializare a membrilor clasei
// Member initialization list
#include <iostream>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana();     // declarari (prototipuri)
    Persoana(string, int);

    void Print()
    {
        cout << nume << ' ' << varsta << '\n';
    }
};

// Definitii externe
Persoana::Persoana() : nume(""), varsta(0)
{
}

Persoana::Persoana(string num, int v) : nume(num), varsta(v)
{
}

int main()
{
    int x(10);
    string nume("Adela");

    Persoana p1;  // Persoana("Ion", 20);
    p1.Print();

    Persoana p2("Adisor", 20);
    p2.Print();
    return 0;
}

