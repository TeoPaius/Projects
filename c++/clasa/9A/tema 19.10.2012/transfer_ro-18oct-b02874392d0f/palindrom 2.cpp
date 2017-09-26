#include<fstream>
using namespace std;

ifstream is ("palindrom.in");
ofstream os ("palindrom.out");

int n, m, inv, aux, l, lmax = 0, aux2, maxim = -9999999;

int main()
{
    is >> m;
    for(int i = 0; i < m;++i)
    {
        is >> n;
        aux = n;
        aux2 = aux;
        for(inv = 0; aux; aux /= 10)
            inv = inv * 10 + aux % 10;
        l = 0;
        while ( aux2 != 0 )
        {
            ++l;
            aux2 /= 10;
        }
        if( l > lmax)
            lmax = l;
        if(n == inv)
            {
                if( n > maxim)
                {
                    maxim = n;
                }
            }
    }
    os << "palindromul este " << maxim;
    os << '\n' << "numarul maxim de cifre al palindromului din fisierul .in este " << lmax;
    is.close();
    os.close();

    return 0;
}
