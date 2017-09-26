// Alocari de memorie pentru obiecte
#include <iostream>
using namespace std;

class Copil {
    string nume;
    int varsta;
public:
    Copil(string num = "Ioana", int v = 17);
    void Print() const
    {
        cout << nume << ' ' << varsta << '\n';
    }
};

Copil::Copil(string num, int v)
        : nume(num), varsta(v)
{
}

Copil c;  // var globala (alocata static)

int main()
{
    // Alocari statice
    Copil c, c1("Ion"), c2("Adi", 18); // Apeluri IMPLICTE ale constructorului

    Copil c3 = Copil();  // Apeluri EXPLICITE ale c-torului
    Copil c4 = Copil("Diana");
    Copil c5 = Copil("Sanda", 19);
    c5.Print();

    // Alocari dinamice (in HEAP)
    Copil* p1 = new Copil;
    Copil* p2 = new Copil("Nelu");
    Copil* p3 = new Copil("Lenuta", 7);
    cout << "Adresa obiectului: " << p3
         << '\n';
    p3->Print();
    delete p1;
    delete p2;

    delete p3;
    cout << "Adresa obiectului: " << p3
         << '\n';
 //   p3->Print();
    return 0;
}
