#include "Carte.h"
#include <iostream>

int main()
{
    Carte c1("Un veac de singuratate", "Marquez", 25);
    Carte c2 = c1; // Bitwise copy
    Carte c3(c2);   // Carte(c2)

    Carte c4 = Carte(c3, "Toamna Patriarhului");
    c4.Print();

}
