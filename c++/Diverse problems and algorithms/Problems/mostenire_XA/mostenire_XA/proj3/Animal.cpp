#include "Animal.h"
#include <iostream>

// functiile din Animal
Animal::Animal() : specia("mamifer")
{
}

Animal::Animal(std::string sp)
    : specia(sp)
{
}

std::string Animal::Get() const
{
    return specia;
}


