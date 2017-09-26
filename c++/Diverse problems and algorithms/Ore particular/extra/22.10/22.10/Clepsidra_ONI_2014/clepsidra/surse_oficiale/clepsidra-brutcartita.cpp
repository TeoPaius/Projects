//Vlad Gavrila - O(N*M)

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 100010
#define mod 666013

int n, m, a, b, cc;
int p2[maxn], f[maxn];
vector<int> v[maxn];

void df(int nod)
{
    if(f[nod])
        return;

    f[nod]=1;

    for(int i=0; i<v[nod].size(); ++i)
        df(v[nod][i]);
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

    p2[0]=1;
    for(int i=1; i<=n; ++i)
        p2[i]=(p2[i-1]*2)%mod;


    for(int i=1; i<=n; ++i)
    {
        memset(f, 0, sizeof(f));
        f[i]=1;
        cc=0;

        for(int j=1; j<=n; ++j)
        {
            if(f[j]==0)
            {
                ++cc;
                df(j);
            }
        }

        printf("%d\n", (p2[cc]-2+mod)%mod);
    }

    return 0;
}

