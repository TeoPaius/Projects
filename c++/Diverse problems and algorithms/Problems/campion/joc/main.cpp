#include <fstream>
using namespace std;

ifstream is("joc.in");
ofstream os("joc.out");

void Golire();

int n;
int c[1000];
int g = 0;
int io = 0;
int cg = 0;
int ci = 0;

int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
        is >> c[i];
    while(n > 2)
    {
        Golire();
        if(n % 2 == 0)
        {
            g += c[n / 2];
            g += c[n / 2 + 1];
            n /= 2;
            n--;
            cg += 2;
        }
        else if(n % 2 == 1)
        {
            g += c[n / 2 + 1];
            n /= 2;
            cg++;
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        io += c[i];
        ci++;
    }

    os << cg << ' ' << g << '\n';
    os << ci << ' ' << io;


    is.close();
    os.close();
    return 0;
}

void Golire()
{
    for(int i = 1; i <= n / 2; ++i)
    {
        c[i] += c[n - i + 1];
        c[n - i + 1] = 0;
    }
}
