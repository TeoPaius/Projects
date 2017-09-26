#include <fstream>
using namespace std;

ifstream is("livada.in");
ofstream os("livada.out");

int m;
long n;
long p;
long maj;
long nr;
long pomi[7001];
int Copaci();
int cnt;
int secvmax;
int secv = 1;

int main()
{
    is >> m >> n >> p;
    maj = n / 2 + 1;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            is >> pomi[j];
            if(pomi[j] == pomi[j - 1])
                secv++;
            else
            {
                if(secv > secvmax)
                    secvmax = secv;
                secv = 1;
            }

        }
        nr = Copaci();
        if(nr >= maj)
            cnt++;

    }
    os << cnt << '\n';
    os << secvmax;
    is.close();
    os.close();
    return 0;
}

int Copaci()
{
    long maxim = -1;
    long nrp[980] = {0};
    for(int i = 1; i <= n; ++i)
    {
        nrp[pomi[i]]++;
        if(nrp[pomi[i]] > maxim)
            maxim = nrp[pomi[i]];
    }
    return maxim;
}
