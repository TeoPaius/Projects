#ifndef ANIMALS_H
#define ANIMALS_H

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

class Caine : public Animal {
    std::string rasa;
    int varsta;
public:
    Caine();
    Caine(std::string, std::string, int);
    void Show() const;
};


#endif // ANIMALS_H
