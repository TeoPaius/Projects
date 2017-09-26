
#include <iostream>
using namespace std;

class Persoana {
    string nume;
    int varsta;
public:
    Persoana(string num = "Ion", int v = 20)
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
    Persoana p1;  // Persoana("Ion", 20);
    p1.Print();

    Persoana p2("Adisor", 20);
    p2.Print();
    return 0;
}

