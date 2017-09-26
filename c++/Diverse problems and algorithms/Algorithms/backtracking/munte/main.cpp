#include <fstream>
#include <cmath>
using namespace std;
ifstream is("munte.in");
ofstream os("munte.out");

int n;
int a[64001];
int ap[64001];
int maxim = -1;
int maxap = 1;
int comb;
bool ok = true;
int p;
bool sunt;

int main()
{
    is >> n;
    for(int i = 0; i < n; ++i)
    {
        is >> a[i];
        ap[a[i]]++;
        if(ap[a[i]] == 2)
            p++;
        if(ap[a[i]] == 3)
        {
            ok = false;
            p--;
        }
        if(a[i] == maxim)
        {
            maxap++;
            sunt = true;
        }
        if(a[i] > maxim)
        {
            maxim = a[i];
            maxap = 1;
        }
    }
    if(maxap >= 2 || !ok)
        os << 0;
    else
    {
        if(sunt)
        {
            comb = pow(2, n-p-2);
        }
        else
        {
            comb = pow(2, n-1) - 2;
        }
        os << comb;
    }

    is.close();
    os.close();
    return 0;
}
