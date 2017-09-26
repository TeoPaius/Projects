#include <fstream>
using namespace std;
ifstream is("secv.in");
ofstream os("secv.out");

int n;
int a[30001];
int minim = 10001;
int maxim = -10001;
int s;
int x, y, z;
int nr;

int main()
{
    is >> n;
    for(int i = 1; i <= n; i++)
    {
        is >> a[i];
        if(a[i] < minim)
        {
            minim = a[i];
            nr = i;
        }
    }
    maxim = -10001;
    for(int i = 1; i <= nr - 1; ++i)
    {
        if(a[i] > maxim)
            maxim = a[i];
    }
    s += maxim;

    s += a[nr];

    maxim = -10001;
    for(int i = nr + 1; i <= n; ++i)
    {
        if(a[i] > maxim)
            maxim = a[i];
    }
    s += maxim;

    os << s << '\n';
    os << nr - 1 << ' ' << nr ;

    is.close();
    os.close();
    return 0;
}
