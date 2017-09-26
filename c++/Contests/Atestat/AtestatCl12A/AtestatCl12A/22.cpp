#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int n;
int a[100];

int Perm(int x)
{
    int nr = 0;
    int p = x;
    int b[11] = {0};
    while(p)
    {
        nr++;
        p/=10;
    }
    p = x;
    for(int i = nr; i >= 1; --i)
    {
        b[i] = p%10;
        p/=10;
    }
    p = 0;
    while(p != x)
    {
        p = 0;
        int aux = b[1];
        for(int i = 2; i <= nr; ++i)
        {
            b[i-1] = b[i];
        }
        b[nr] = aux;
        for(int i = 1; i <= nr; ++i)
        {
            p += b[i];
            p *= 10;
        }
        p /= 10;
        if(p < x)
        {
            return p;
        }
    }
    return 0;

}

int main()
{
    is >> n;
    int cnt = 0;
    int rez[100] ={0};
    for(int i = 1; i <= n; ++i)
    {
        is >> a[i];
        if(Perm(a[i])!= 0)
        {
            cnt++;
            rez[cnt] = Perm(a[i]);
        }
    }
    os << cnt << '\n';
    for(int i = 1; i <= cnt;++i)
    {
        os << rez[i] << ' ';
    }
    is.close();
    os.close();
    return 0;
}
