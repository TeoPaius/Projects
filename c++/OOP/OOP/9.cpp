// Lista de initializare a membrilor clasei
// Member initialization list
#include <iostream>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana() : nume(""), varsta(0)
    {
    }
    Persoana(string num, int v) : nume(num), varsta(v)
    {
    }

    void Print()
    {
        cout << nume << ' ' << varsta << '\n';
    }
};

int main()
{
    Persoana p1;  // Persoana("Ion", 20);
    p1.Print();

    Persoana p2("Adisor", 20);
    p2.Print();
    return 0;
}

