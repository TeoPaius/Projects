#include "Carte.h"
#include <iostream>

Carte::Carte(std::string t, std::string a, int p)
    : titlu(t), autor(a), pret(p)
{
}

Carte::Carte(const Carte& c)
    : titlu(c.titlu), autor(c.autor), pret(c.pret + 10)
{
}

Carte::Carte(const Carte& c, std::string t)
    : titlu(t), autor(c.autor), pret(c.pret)
{
}

void Carte::Print() const
{
    std::cout << titlu << ' ' << autor << ' '
              << pret << std::endl;
}

