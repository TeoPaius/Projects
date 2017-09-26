#include <iostream>
using namespace std;

class Carte {
    string titlu;
    int an;
public:
    Carte(string t, int a) : titlu(t), an(a)
    {
    }
    Carte() : titlu(""), an(0)
    {
    }
    void Print() const
    {
        cout << titlu << ' ' << an << '\n';
    }

};

int main()
{
    //Alocari statice
    // Apel IMKPLICIT Carte()
    Carte c1;
    // Apel IMPLICIT Carte(string, int)
    const Carte c2("Ion", 1935);

    // Apeluri explicite
    Carte c3 = Carte();
    Carte c5 = Carte("Rascoala", 1932);
    c1.Print();
    c2.Print();

    // Alocari dinamice
    Carte* p = new Carte();
    delete p;
    p = new Carte;
    delete p;

    p = new Carte("Iarna vrajbei noastre", 1937);

    return 0;
}

