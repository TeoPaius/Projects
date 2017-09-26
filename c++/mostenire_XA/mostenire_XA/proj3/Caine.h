#ifndef CAINE_H
#define CAINE_H

#include <string>
#include "Animal.h"

class Caine : public Animal {
    std::string rasa;
    int varsta;
public:
    Caine();
    Caine(std::string, std::string, int);
    void Show() const;
};


#endif // CAINE_H

