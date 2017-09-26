#include <iostream>
using namespace std;

// definim un nou tip de date
class Copil {
    // Date Membre (campuri)
    string nume;
    int varsta;
public:
    Copil()
    {
        nume = "Nicu";
        varsta = 17;
    }
    Copil(string num, int v)
    {
        nume = num;
        varsta = v;
    }
    // Functii membre
    void Print() const
    {
        cout << nume << ' ' << varsta << '\n';
    }
    void SetName(string num)
    {
        nume = num;
    }
    string GetName() const
    {
        return nume;
    }
};

int main()
{
    Copil c1;
    c1.SetName("Ioana");
    cout << c1.GetName();

    const Copil c2("Valentin", 16);
    c2.Print();
    c2.SetName("Adi");
    return 0;
}
