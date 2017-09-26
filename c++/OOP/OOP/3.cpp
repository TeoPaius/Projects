/* Functii care au parametri cu valori implicite
*/
#include <iostream>
#include <string>
using namespace std;

void Scrie(string nume = "Gicutu", int varsta = 16, char sex = 'F')
{
    cout << nume << ' ' << varsta << ' ' << sex << '\n';
}

int main()
{
    Scrie("Nelutu", 16, 'M' );
    Scrie("Gelutu", 17);
    Scrie("Alinuta");
    Scrie();
    return 0;
}

