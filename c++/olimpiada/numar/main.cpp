#include <fstream>
#include <cmath>
using namespace std;

ifstream is("numar.in");
ofstream os("numar.out");

int Nr_cif(int x);

int n;
int a[10001];
int cif[10001];
int numar;
int maxim = 0;

int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> a[i];
        cif[i] = Nr_cif(a[i]);
    }
    for(int i = 1; i < n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(a[i] != a[j])
            {
                int k = pow(10, cif[j] - 1);
                if(a[i] % 10 == a[j] / k )
                {
                    numar = a[i] * k * 10 + a[j];
                    if(numar >= maxim)
                        maxim = numar;
                }
            }
        }
    os << maxim;

    is.close();
    os.close();
    return 0;
}

int Nr_cif(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}
