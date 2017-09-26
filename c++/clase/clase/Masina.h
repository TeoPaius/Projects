#ifndef MASINA_H
#define MASINA_H

using namespace std;
#include <string>

class Masina{

    int pret;
    string culoare;
    int ani;
public:
    Masina();
    Masina(int p , string c  , int a);
    Masina(const Masina& m);

    void SetPret(int p);
protected:
    int GetPret();

};


class Roata : public Masina{
    int diametru;
    string culoare;
public:
    Roata();
    Roata(int d, string s);
    void Show();

};


#endif // MASINA_H
