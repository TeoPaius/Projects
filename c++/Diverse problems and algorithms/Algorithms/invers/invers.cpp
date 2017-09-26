#include <fstream>
using namespace std;

ifstream is("invers.in");
ofstream os("invers.out");

int main()
{
    int n, aux, x, inv, lmax = 0, l, max = 0;
    is >> n;
    for(int i = 0; i < n; ++i)
    {
        is >> x;
        if (x > max )
            max = x;
        aux = x;
        inv = 0;
        while(aux != 0)
        {
            inv = inv * 10 + aux % 10;
            aux /= 10;
        }
        if (inv == x )
        {
            l = 0;
            while(inv != 0)
            {
                l++;
                inv /= 10;
            }
            if (l > lmax )
                lmax = l;
            else
                l = 0;
        }

    }
    os << max << " de lungime " << lmax;

    return 0;
    is.close();
    os.close();


}
