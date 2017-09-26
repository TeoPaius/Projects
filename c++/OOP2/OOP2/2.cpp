// Function Overloading (Supraincarcarea functiilor )
/*
   Functiile pot fi supraincarcate daca difera prin
   numarul si/sau tipul parametrilor formali
   (signatura functiei)
*/
#include <iostream>
#include <string>
using namespace std;

void F() { }
void F(int) { }       // OK
void F(int, int) { }  // OK
void F(char) { }      // OK
void F(int a, string b) { } // OK

int F(int) { }  // NO !!!

int main()
{
}
