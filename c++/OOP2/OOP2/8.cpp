// Lista de initializare a membrilor clasei
// Member intialization list
#include <iostream>
#include <string>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana();
    Persoana(string, int);

    void Print()
    {
        cout << nume << ' ' << varsta << '\n';
    }
};

Persoana::Persoana() : nume("Ion"), varsta(20)
{
}

Persoana::Persoana(string num, int v)
    : nume(num), varsta(v)
{
}

int main()
{
    Persoana p1;  // Persoana()
    p1.Print();

    Persoana p2("Adina", 16);
    p2.Print();
}
