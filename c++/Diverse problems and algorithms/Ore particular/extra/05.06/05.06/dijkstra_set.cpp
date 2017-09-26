#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define MAXN 50100
#define INF 1000000000
 
int N, M, d[MAXN]; vector<int> G[MAXN], C[MAXN];
set< pair<int, int> > T;
 
void solve(void)
{
    int i, j, k, val, x;
     
    for(i = 2; i <= N; i++) d[i] = INF;
    T.insert( mp(0, 1) );
 
    while( T.size() > 0 )
    {
        val = T.begin()->first, x = (*T.begin()).second;
        T.erase(*T.begin());
        for(i = 0; i < G[x].size(); i++)
         if(d[ G[x][i] ] > val + C[x][i] )
            d[ G[x][i] ] = val + C[x][i], T.insert(mp(d[G[x][i]],G[x][i]));
    }
}
 
int main(void)
{
    freopen("dijkstra.in", "rt", stdin);
    freopen("dijkstra.out", "wt", stdout);
 
    int i, a, b, c;
 
    scanf("%d %d\n", &N, &M);
 
    for(i = 1; i <= M; i++)
        scanf("%d %d %d\n", &a, &b, &c), G[a].pb(b), C[a].pb(c);
 
    solve();
 
    for(i = 2; i <= N; i++)
        printf("%d ", d[i] == INF ? 0 : d[i]);
 
    return 0;
}
