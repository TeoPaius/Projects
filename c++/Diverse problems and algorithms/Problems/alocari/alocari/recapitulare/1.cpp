/*Se citesc doua cuvinte A si B cu cel mult 20litere fiecare, afisati sufixele din cuvantul
A care sunt prefixe ale cuvantului B.Daca nu exista astfel de prefixe se va scrie :
"NU EXISTA!".
*/
#include <fstream>
#include <cstring>
using namespace std;

ifstream is("1.in");
ofstream os("1.out");

int main()
{
    char a[21];
    char b[21];
    char aux[21];
    char aux1[21];
    is >> a;
    is.get();
    is >> b;
    for ( int i = 0; i <= min(strlen(a), strlen(b)); ++i )
    {
        aux[i] = a[strlen(a) - i + 1];
        aux1[i] = b[i];
        if ( aux == aux1 )
            os << aux << ' ';
    }
    return 0;
    is.close();
    os.close();
}
