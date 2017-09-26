#include <fstream>
using namespace std;
ifstream is ("bile.in");
ofstream os ("bile.out");

int t[64000];
int a[251][251];
int sol[64000];
struct Bila{
    int col;
    int lin;
};
Bila b[64000];
int n;
int H;
int h[64000];
int hmax;
int cnt = 1;

int Find(int x);

int main()
{
    is >> n;
    for(int i = 1; i <= n * n; ++i)
    {
        is >> b[n*n - i + 1].lin;
        is >> b[n*n - i + 1].col;
    }
    for(int i = 1; i <= n * n; ++i)
    {
        a[b[i].lin][b[i].col] = i;
        if( a[b[i].lin - 1][b[i].col] == 0 && a[b[i].lin][b[i].col + 1] == 0 && a[b[i].lin + 1][b[i].col] == 0 && a[b[i].lin][b[i].col - 1] == 0)
            {
                t[i] = i;
                h[i] = 1;
            }
        else
        {
            H = 1;
            int rad;
            if(a[b[i].lin - 1][b[i].col] != 0)
            {
                rad = Find(a[b[i].lin-1][b[i].col]);
                H += h[rad];
                t[rad] = i;
                t[i] = i;
            }
            if(a[b[i].lin][b[i].col + 1] != 0)
            {
                rad = Find(a[b[i].lin][b[i].col + 1]);
                H += h[rad];
                t[rad] = i;
                t[i] = i;
            }
            if(a[b[i].lin + 1][b[i].col] != 0)
            {
                rad = Find(a[b[i].lin + 1][b[i].col]);
                H += h[rad];
                t[rad] = i;
                t[i] = i;

            }
            if(a[b[i].lin][b[i].col - 1] != 0)
            {
                rad = Find(a[b[i].lin][b[i].col - 1]);
                H += h[rad];
                t[rad] = i;
                t[i] = i;
            }
            h[i] = H;
        }
        if(h[i] > hmax)
        {
            hmax = h[i];
        }
        sol[cnt] = hmax;
        cnt++;
    }
    for(int i = n * n - 1; i >= 0; --i)
        os << sol[i] << '\n';
    is.close();
    os.close();
    return 0;
}

int Find(int x)
{
    if (x == t[x])
        return x;
    return t[x] = Find(t[x]);
}
