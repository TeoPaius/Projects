#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte {
    std::string titlu; // Fully qualified name
    std::string autor;
    int pret;
public:
    Carte(std::string = "Ion",
          std::string = "Rebreanu",
          int = 20);
    Carte(const Carte&);
    Carte(const Carte& c, std::string);
    void Print() const;
};

#endif  // CARTE_H
