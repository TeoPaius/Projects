#include <fstream>
#include <algorithm>
using namespace std;
ifstream is("cladire.in");
ofstream os("cladire.out");

bool Verificare(int x);
bool Patrat(int x, int y, int z);


struct Punct{
    int lin;
    int col;
}p[100000];

bool a[1001][1001] ;
int m, n;
int k;
int l;
bool ok = false;

int main()
{
    is >> m >> n;
    is >> k;
    int ic, jc;
    for(int i = 1; i <= k; ++i)
    {
        is >> ic >> jc;
        a[ic][jc] = true;
        p[i].lin = ic;
        p[i].col = jc;
    }

    int aux;
    if(m > n)
        aux = n;
    else
        aux = m;

    int l;
    for(l = aux; ok == false; )
    {
        if(Verificare(l) == true)
            ok = true;
        else
            --l;
    }

    os << l;
    is.close();
    os.close();
    return 0;
}

bool Verificare(int x)
{
    for(int i = 1; i <= m - x + 1; ++i)
    {

        for(int j = 1; j <= n - x + 1; ++j)
        {
            if(i == 3 && j == 3)
             int jjj=9;
            if(Patrat(i, j, x) == true)
                return true;
        }
    }
    return false;

}

bool Patrat(int x, int y, int z)
{
    for(int h = 1; h <= k; ++h)
    {
        if(p[h].lin >= x && p[h].lin < x + z)
            if(p[h].col >= y && p[h].col < y + z)
            {
                return false;
            }
    }
    return true;
}



