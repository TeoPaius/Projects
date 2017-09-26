#include <fstream>
#include <cmath>
using namespace std;

ifstream is("copii.in");
ofstream os("copii.out");

struct Copii{
    int nr;
    bool pus;
};

bool Nr_prim(int x);

int n;
Copii a[1001];
int b[1001];
int aux;
int cnt;

int main()
{
    is >> n;
    for(int i = 1; i <= 2*n; ++i)
    {
        a[i].nr = i;
        a[i].pus = true;
    }
    int cnt = 2 * n;
    int i = 1;
    int k = 4;
    while(cnt > 0)
    {
        if(k == 4 && a[i].pus)
        {
            a[i].pus = false;
            cnt--;
            b[2 * n - cnt] = a[i].nr;
            k = 0;
        }
        ++i;
        if(i == 2 * n + 1)
            i = 1;
        if(a[i].pus)
        {
            k++;
        }

    }


    int aux = 2 * n;
    for(int j = 1; j <= 2 * n; )
    {
        while(aux >= 1)
        {
            if(Nr_prim(aux))
            {
                a[b[j]].nr = aux;
                j++;
            }
            aux--;
        }
        while(aux <= 2 * n)
        {
            if(Nr_prim(aux) == false && aux )
            {
                a[b[j]].nr = aux;
                j++;
            }
            aux++;
        }
    }
    for(int j = 1; j <= 2 * n; ++j)
        os << a[j].nr << ' ';

    is.close();
    os.close();
    return 0;
}

bool Nr_prim(int x)
{
    if(x == 0)
        return false;
    if(x == 1)
        return true;
    if(x == 2)
        return true;
    if(x % 2 == 0)
        return false;
    int d = 3;
    while(d * d <= x)
    {
        if(x % d == 0)
            return false;
        d += 2;
    }
    return true;
}

