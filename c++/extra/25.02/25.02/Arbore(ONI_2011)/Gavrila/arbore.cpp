#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 100010
#define maxc 2010
#define mod 666013

int n, i, j, k, sol, a, b, d[maxn], coa[maxn];
int cmb[maxc][maxc], f[maxn], fact[maxn], imod[maxn];
vector<int> v[maxn];

int lgput(int nr, int exp)
{
    if(exp==0)
        return 1;
    int aux=lgput(nr, exp/2);
    if(exp%2)
        return (((1LL*aux*aux)%mod)*nr)%mod;
    return (1LL*aux*aux)%mod;
}

int combinari(int nr, int k)
{
    if(n<=2000)
        return cmb[nr][k];
    return (((1LL*fact[nr]*imod[k])%mod)*imod[nr-k])%mod;
}

void bf()
{
    coa[0]=1;
    coa[1]=1;
    f[1]=1;
    for(int i=1; i<=coa[0]; ++i)
    {
        int nod=coa[i];
        for(int j=0; j<v[nod].size(); ++j)
        {
            int fiu=v[nod][j];
            if(f[fiu]==0)
            {
                f[fiu]=1;
                coa[++coa[0]]=fiu;
            }
        }
    }
    for(int i=coa[0]; i; --i)
    {
        int nod=coa[i];
        f[nod]=2;
        for(int j=0; j<v[nod].size(); ++j)
        {
            int fiu=v[nod][j];
            if(f[fiu]==2)
            {
                d[nod]+=d[fiu];
                sol=(1LL*sol*combinari(d[nod], d[fiu]))%mod;
            }
        }
        d[nod]++;
    }
}

int main()
{
    freopen("arbore.in", "r", stdin);
    freopen("arbore.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    if(n<=2000)
    {
        cmb[0][0]=1;
        for(int i=1; i<=n; ++i)
        {
            cmb[i][0]=1;
            for(int j=1; j<=i; ++j)
                cmb[i][j]=(cmb[i-1][j]+cmb[i-1][j-1])%mod;
        }
    }
    else
    {
        fact[0]=1;
        imod[0]=1;
        for(int i=1; i<=n; ++i)
        {
            fact[i]=(1LL*fact[i-1]*i)%mod;
            imod[i]=(1LL*imod[i-1]*lgput(i, mod-2))%mod;
        }
    }

    sol=1;
    bf();

    printf("%d\n", sol);
    return 0;
}
