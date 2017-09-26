//Vlad Gavrila - O(N+M)

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 200010
#define mod 666013

int n, m, a, b, cc;
int f[maxn], tata[maxn], sol[maxn], niv[maxn], d[maxn];
vector<int> v[maxn];

void df(int nod)
{
    if(f[nod])
        return;

    int fiu, cc=0;

    f[nod]=1;
    d[nod]=niv[nod];

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        if(fiu==tata[nod])
            continue;
        if(f[fiu])
        {
            d[nod]=min(d[nod], niv[fiu]);
            continue;
        }

        niv[fiu]=niv[nod]+1;
        tata[fiu]=nod;
        df(fiu);

        if(d[fiu]>=niv[nod])
            ++cc;
        d[nod]=min(d[nod], d[fiu]);
    }

    if(tata[nod]!=0)
        ++cc;

    sol[nod]=cc;
}

inline int p2(int N) {
    int ret = 1, P = N;
    N = 2;
    while (P) {
        if (P & 1)
            ret = (1LL * ret * N) % mod;
        N = (1LL * N * N) % mod;

        P >>= 1;
    }

    return ret;
}

int main()
{
    freopen("clepsidra.in", "r", stdin);
    freopen("clepsidra.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    niv[1]=1;
    df(1);

    for(int i=1; i<=n; ++i)
        printf("%d\n", (p2(sol[i])-2+mod)%mod);

    return 0;
}
