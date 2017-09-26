/*Se citeste un numar natural n apoi inca n numere naturale.
Sa se afiseze acele numere ce au proprietatea de palindrom. */
#include<fstream>
using namespace std;

ifstream is ("palindrom.in");
ofstream os ("palindrom.out");

int n, m, p, inv, aux, l = 0, lmax = 0;

int main()
{
    is >> m;
    for(int i = 0; i < m; ++i)
    {
        is >> n;
        aux = n;
        p = n;
        for(inv = 0; aux; aux /= 10)
            inv = inv * 10 + aux % 10;
        while(p != 0)
        {
            l++;
            p /= 10;
        }
        if (l > lmax)
        {
            lmax = l;
        }
        os << lmax;
    }
    is.close();
    os.close();

    return 0;
}
