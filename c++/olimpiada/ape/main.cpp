#include <fstream>
using namespace std;
ifstream is ("ape.in");
ofstream os ("ape.out");

int n;
char p[10001];
int a[10001][10001];
int imin, imax, jmin, jmax;
int ii, jj;

int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> p[i];
        if(p[i] == 'N')
        {
            ++ii;
            if(ii > imax)
                imax = ii;
        }
        if(p[i] == 'S')
        {
            --ii;
            if(ii < imin)
                imin = ii;
        }
        if(p[i] == 'V')
        {
            --jj;
            if(jj < jmin)
                jmin = jj;
        }
        if(p[i] == 'E')
        {
            ++jj;
            if(jj > jmax)
                jmax = jj;
        }
    }
    os << imax - 1 - imin;
    os <<'\n';
    os << jmax - 1 - jmin;
    os << '\n';



    is.close();
    os.close();
    return 0;
}
