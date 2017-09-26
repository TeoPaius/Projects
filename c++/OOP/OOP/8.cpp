
#include <iostream>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana(string = "Ion", int sdhksjdhfkljsdfh = 20);
    void Print();
};

void Persoana::Print()
{
    cout << nume << ' ' << varsta << '\n';
}

Persoana::Persoana(string num, int v)
{
    nume = num;
    varsta = v;
}

int main()
{
    Persoana p1;  // Persoana("Ion", 20);
    p1.Print();

    Persoana p2("Adisor", 20);
    p2.Print();
    return 0;
}

