#include <iostream>
using namespace std;

struct Copil {
    // Date Membre (campuri)
    string nume;
    int varsta;

    // Functii membre
    void Print()
    {
        cout << nume << ' '  << varsta << '\n';
    }
};


int main()
{
    Copil c;
    c.nume = "Ioana";
    c.varsta = 18;
    return 0;
}
