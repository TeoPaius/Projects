#include <fstream>
using namespace std;
ifstream is("anagramabil.in");
ofstream os("anagramabil.out");

bool Verificare(int x);

long int n;
int c[10];
int cnt;
bool este;

int main()
{
    is >> n;
    int aux = n;
    while(aux)
    {
        if(c[aux % 10] == 0)
        {
            c[aux % 10] = 1;
        }
        aux /= 10;
    }
    for(int i = 2; i <= 9; ++i)
    {
        aux = n * i;
        if(Verificare(aux))
        {
            if(!este)
                os << "DA" << '\n';
            os << i;
            este = true;
        }
    }
    if(!este)
        os << "NU";


    is.close();
    os.close();
    return 0;
}

bool Verificare(int x)
{
    int cif[10] = {0};
    while(x)
    {
        cif[x % 10] = 1;
        x /= 10;
    }
    for(int i = 0; i <= 9; ++i)
    {
        if(cif[i] != c[i])
            return false;
    }
    return true;


}
