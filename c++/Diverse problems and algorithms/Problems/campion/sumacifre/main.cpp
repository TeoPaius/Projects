#include <fstream>
#include <cmath>
using namespace std;

ifstream is("sumacifre.in");
ofstream os("sumacifre.out");

int Invers(int x);

int n, k;

int main()
{
    is >> n;
    is >> k;
    int nrf = 0;
    int s = 0;
    int nr1, nr2;
    float d;

    while(k > 0)
    {
        nrf = 0;
        if(n < 10)
            s += n;
        else
        {
            while(n >= 10)
            {
                nr1 = n % 10;
                n /= 10;
                nr2 = n % 10;
                d = nr1 - nr2;
                nrf = nrf * 10 + abs(d);
            }
            n = Invers(nrf);
            s += n;
        }
        --k;
    }
    os << s;
    is.close();
    os.close();
    return 0;
}

int Invers(int x)
{
    int invers = 0;
    while(x)
    {
        invers = invers * 10 + x % 10;
        x /= 10;
    }
    return invers;
}
