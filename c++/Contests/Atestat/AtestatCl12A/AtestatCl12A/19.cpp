#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int n;
int a[100][100];


int main()
{
    int maxim = -INF;
    int minim = INF;
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            is >> a[i][j];
            if(a[i][j] < minim)
            {
               minim = a[i][j];
            }
            if(a[i][j] > maxim)
            {
                maxim = a[i][j];
            }
        }
    }
    bool ok = false;
    for(int i = 1; i <= n; ++i)
    {
        ok = false;
        for(int j = 1; j <= n; ++j)
        {
            if(a[i][j] == maxim)
            {
                ok = true;
            }
        }
        if(ok == true)
        {
            for(int j = 1; j <= n; ++j)
            {
                a[i][j]+= minim;
            }

        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            os << a[i][j] << ' ';
        }
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}
