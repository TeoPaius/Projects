// Function OVERLOADING (Supraincarcarea functiilor)
#include <iostream>
using namespace std;

/* Functiile pot fi supraincarcate daca difera prin
   numarul si/sau tipul parametrilor formali
*/
void F() { }
void F(int) { }       // OK
void F(int, int) { }  // OK
void F(int, char) { } // OK
void F(char, int) { } // OK
void F(double) { }    // OK

int  F(int) { }       // NO !!!

int main()
{
    return 0;
}

