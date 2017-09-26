#include <iostream>
#include <string>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana(string = "Adi", int = 16);
    void Print();
};

Persoana::Persoana(string num, int v)
{
    nume = num;
    varsta = v;
}

void Persoana::Print()
{
    cout << nume << ' ' << varsta << '\n';
}


int main()
{
    Persoana p1;  // Persoana("Adi", 16)
    p1.Print();

    Persoana p2("Adina", 16);
    p2.Print();
}
