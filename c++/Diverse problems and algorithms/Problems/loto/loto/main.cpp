#include <fstream>
#include <algorithm>
using namespace std;
ifstream is("loto.in");
ofstream os("loto.out");

int n, s;
int a[110];

struct loto{
    int s, i, j, k;
}b[1000010];

int Caut(int st, int dr, int sum);
bool Ok(loto a, loto b);

int main()
{
    is >> n >> s;
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        is >> a[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
            for(int k = j; k <= n; ++k)
            {
                cnt++;
                b[cnt].s = a[i] + a[j] + a[k];
                b[cnt].i = a[i];
                b[cnt].j = a[j];
                b[cnt].k = a[k];
            }
    sort(b+1,b+cnt+1,Ok);
    int c;
    bool gasit = false;
    for(int i = 1; i <= cnt; ++i)
    {
        c = Caut(1, cnt, s-b[i].s);
        if(c)
        {
            os << b[i].i  << ' ' << b[i].j  << ' ' << b[i].k  << ' ' << b[c].i << ' '<< b[c].j << ' ' << b[c].k;
            gasit = true;
            break;
        }
    }

    if(!gasit)
        os << -1;
    is.close();
    os.close();
    return 0;
}

int Caut(int st, int dr, int sum)
{
    int m;
    while(st <= dr)
    {
        m = (st + dr) / 2;
        if(b[m].s == sum)
            return m;
        if(b[m].s < sum)
            st = m + 1;
        if(b[m].s > sum)
            dr = m - 1;
    }
    return 0;
}

bool Ok(loto a, loto b)
{
    return a.s < b.s;
}
