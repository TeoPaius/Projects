#include <iostream>
#include <string>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana(string num = "Adi", int v = 16)
    {
        nume = num;
        varsta = v;
    }
    void Print()
    {
        cout << nume << ' ' << varsta << '\n';
    }
};

int main()
{
    Persoana p1;  // Persoana("Adi", 16)
    p1.Print();

    Persoana p2("Adina", 16);
    p2.Print();
}
