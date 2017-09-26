#include "Masina.h"
#include <iostream>

Masina :: Masina() : pret(15), culoare("red"), ani(100)
{
}

Masina :: Masina(int p = 1 , string c ="" , int a = 0 )
{
    pret = p;
    culoare = c;
    ani = a;
}

Masina :: Masina(const Masina& m)
{
    pret = m.pret;
    culoare = m.culoare;
    ani = m.ani;
}

int Masina :: GetPret()
{
    return pret;
}

void Masina :: SetPret(int p)
{
    pret = p;
}






Roata::Roata() : diametru(0), culoare("alb")
{

}

Roata::Roata(int d , string s )
{
    diametru = d;
    culoare =  s;
}

void Roata::Show()
{
    cout << diametru << ' ' << culoare << GetPret();
}
