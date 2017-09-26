#include <fstream>
#include <cmath>
using namespace std;
ifstream is("prodmax.in");
ofstream os("prodmax.out");

int Nr_cif(int x);

long long int n;
long long int nr1, nr2;
long long int p;
long long int pmax = -1;
int nc;

int main()
{
    is >> n;
    nc = Nr_cif(n);
    long long int x;
    for(int i = 1; i < nc; ++i)
    {
        x = pow((double)10, (double)(nc - i));
        p = (n % x) * (n / x);
        if(p > pmax)
        {
            pmax = p;
            nr2 = n % x;
            nr1 = n / x;
        }

    }
    os << pmax << '\n' << nr1 << '\n' << nr2;

    is.close();
    os.close();
    return 0;
}

int Nr_cif(int x)
{
    int cif = 0;
    while(x)
    {
        cif++;
        x /= 10;
    }
    return cif;
}
