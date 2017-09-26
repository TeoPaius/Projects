#include <iostream>
#include "Caine.h"
// Functiile clasei Caine

Caine::Caine()
    : rasa("labrador"),  varsta(4)
{
}

Caine::Caine(std::string sp, std::string r, int v)
    : Animal(sp), rasa(r),  varsta(v)
{
}

void Caine::Show() const
{
    std::cout << Get() << ' ' << rasa
              << varsta << '\n';
}


