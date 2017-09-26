#include "..\include\Animals.h"
#include <iostream>
using namespace std;
// functiile din Animal
Animal::Animal() : specia("mamifer")
{
}

Animal::Animal(std::string sp)
    : specia(sp)
{
}

string Animal::Get() const
{
    return specia;
}

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
