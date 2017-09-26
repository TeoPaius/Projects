#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
    std::string specia;
public:
    Animal();
    Animal(std::string);
protected:
    std::string Get() const;
};

#endif // ANIMAL_H

