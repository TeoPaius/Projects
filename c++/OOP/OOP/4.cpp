/* Functii care au parametri cu valori implicite
*/
#include <iostream>
#include <string>
using namespace std;

void F(string s = "Ion", int v = 16, char c = 'M', double m = 7.5); // OK
void G(string s, int v = 20, char c = 'F', double m = 7.4); // OK
void H(string s, int v, char c = 'M', double m = 7.8); // OK
void I(string s, int v, char c, double m = 7.8); // OK
void J(string s, int v, char c, double m = 7.8); // OK
void K(string s = "Adi", int v, char c, double m = 7.8); // NO !
void L(string s, int v = 10, char c, double m = 7.8); // NO!

int main()
{
    return 0;
}

