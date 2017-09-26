#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define MAXN 50100
#define INF 1000000000
 
int N, M, d[MAXN]; 
vector<vector<pair<int, int> > > G;
typedef vector<pair<int, int> >::iterator IT;
 
set<pair<int, int> > T;
 
void Solve(void)
{
    int i, j, k, val, x;
     
    for(i = 2; i <= N; i++) d[i] = INF;
    T.insert( mp(0, 1) );
	int y, dx, cost;
    while( !T.empty() )
    {
        dx = T.begin()->first, x = (*T.begin()).second;
        T.erase(T.begin());
        for(IT it = G[x].begin(); it != G[x].end(); ++it )
        {
			y = it->first;
			cost = it->second;
			if(d[y] > dx + cost )   // if ( d[y] > d[x] + cost )
				d[y] = dx + cost, 
            T.insert(mp(d[y], y));  
		}
    }
}
 
int main(void)
{
    freopen("dijkstra.in", "rt", stdin);
    freopen("dijkstra.out", "wt", stdout);
 
    int i, a, b, c;
 
    scanf("%d %d\n", &N, &M);
	G.resize(N + 1);
    for(i = 1; i <= M; i++)
        scanf("%d %d %d\n", &a, &b, &c), 
        G[a].pb(mp(b, c));
 
    Solve();
 
    for(i = 2; i <= N; i++)
        printf("%d ", d[i] == INF ? 0 : d[i]);
 
    return 0;
}
