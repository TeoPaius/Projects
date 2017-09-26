/* Functii care au parametri cu valori implicite
*/
#include <iostream>
#include <string>
using namespace std;

void Scrie(string = "Adisor", int = 12, char = 'M');

int main()
{
    Scrie("Ion", 16, 'M');
    Scrie("Adina", 18);
    Scrie("Gelutu");
    Scrie();
}

void Scrie(string nume, int varsta, char sex)
{
    cout << nume << ' ' << varsta << ' ' << sex << '\n';
}

