#include <iostream>
using namespace std;

class Copil {
    string nume;
    int varsta;
public:
    Copil();
    Copil(string, int);
    void Print() const;
    void SetName(string);
    string GetName() const;
};

// Definitii externe clasei
Copil::Copil() : nume("Nicu"), varsta(17)
{
}

Copil::Copil(string num, int v)
        : nume(num), varsta(v)
{
}

void Copil::Print() const
{
    cout << nume << ' ' << varsta << '\n';
}

void Copil::SetName(string num)
{
    nume = num;
}

string Copil::GetName() const
{
    return nume;
}

int main()
{
    Copil c1;
    c1.SetName("Ioana");
    cout << c1.GetName() << '\n';

    const Copil c2("Valentin", 16);
    c2.Print();
    return 0;
}
