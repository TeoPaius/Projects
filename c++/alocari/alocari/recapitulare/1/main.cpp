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
    is.getline(a, 20);
    is.getline(b, 20);
    for ( int i = 0; i <= min(strlen(a), strlen(b)); ++i )
        if( strstr(b, a + i) == b )
            os << a + i << " ";
    return 0;
    is.close();
    os.close();
}
