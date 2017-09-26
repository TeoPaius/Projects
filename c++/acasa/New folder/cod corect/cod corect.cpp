#include<fstream>
using namespace std;

ifstream is ("cod corect.in");
ofstream os ("cod corect.out");
int mijloc(int x);
int prima(int x);

int main()
{
    int n, a, aux, l, nr_corect, mijl
    is >> n;
    for ( ;n != 0; --n )
    {
        is >> a;
        aux = a;
        l = 0
        while(aux)
        {
            l++;
            aux /= 10;
        }
        if(l % 2 = 1 && a % 10 > prima(a))
        {
            mijl = mijloc(a)

            nr_corect =  * 10 + prima(a)
        }

    }

}

int mijloc(int x)
{
    int mijl, inv = 0,
    x /= 10;
    while(x != 0)
    {
        inv = inv * 10 + x % 10;
        x /= 10;
    }
    inv /= 10;
    while(inv != 0)
    {
        mijl = mijl * 10 + inv % 10
        inv /= 10;
    }
    return mijl;
}

int prima(int x)
{
    while(x > 10)
    x /= 10;
    return x;
}
