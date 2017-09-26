#include <fstream>
using namespace std;

ifstream is("vase.in");
ofstream os("vase.out");

struct Lichid{
    int unit;
    char poz;
}l[100000];

int n;
int x;
int suma;

int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> l[i].unit;
        is >> l[i].poz;
        suma += l[i].unit;
    }
    is >> x;

    os << suma / 2 << '\n';

    int stanga = l[x].unit / 2;
    int dreapta = l[x].unit / 2;

    for(int i = 1; i <= n; ++i)
    {
        if(i != x)
        {
            if(l[i].poz == 'S')
            {
                stanga = stanga - l[i].unit / 2;
                dreapta = dreapta + l[i].unit / 2;
            }
            if(l[i].poz == 'D')
            {
                stanga = stanga + l[i].unit / 2;
                dreapta = dreapta - l[i].unit / 2;
            }
        }
    }

    if (stanga >= 0)
    {
        os << stanga;
        os << "S";
    }
    else
    {
        os << stanga * (-1);
        os << "D";
    }

    os << '\n';

    if(dreapta >= 0)
    {
        os << dreapta;
        os << "D";
    }
    else
    {
        os << dreapta * (-1);
        os << "S";
    }



    is.close();
    os.close();
    return 0;
}
