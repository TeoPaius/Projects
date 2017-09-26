/* Functii care au parametri cu valori implicite
*/
#include <iostream>
#include <string>
using namespace std;

void F(int a = 2, double b = 3.2, char c = 'L', float d = 8.3 );
void G(int a, double b = 3.2, char c = 'L', float d = 8.3 ); // OK
void H(int a, double b, char c = 'L', float d = 8.3 ); // OK
void I(int a, double b, char c, float d = 8.3 ); // OK

void J(int a = 2, double b, char c = 'L', float d = 8.3 ); // NU
void K(int a, double b = 2.34, char c, float d = 8.3 ); // NU
void K(int a, double b, char c = 'U', float d); // NU

int main()
{
}

