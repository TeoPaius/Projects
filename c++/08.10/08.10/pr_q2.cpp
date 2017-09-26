#include<stdio.h>
#include<queue>
using namespace std;
 
const int NMAX = 50000,INF = 1 << 30;
 
struct Edge {
    int node, cost;
    const bool operator < (const Edge &other) const {
        return cost > other.cost;
        }
    };
 
vector <Edge> G[NMAX + 5];
vector <Edge>::iterator it;
priority_queue <Edge> heap;
 
int vis[NMAX + 5],dmin[NMAX + 5],n;
 
void dijkstra (int k) 
{
    int i;
    for(i = 1; i <= n; i++)
        dmin[i] = INF;
    dmin[1] = 0;
    heap.push({k, 0});
    while(!heap.empty()) 
    {
        k = heap.top().node;
        vis[k] = 1;
        for (auto x : G[k])
            if(!vis[x.node] && dmin[k] + x.cost < dmin[x.node]) 
            {
                dmin[x.node] = dmin[k] + x.cost;
                heap.push({x.node, dmin[x.node]});
            }
        while(!heap.empty() && vis[heap.top().node])
            heap.pop();
    }
}
 
int main() 
{
    freopen("dijkstra.in","r",stdin);
    freopen("dijkstra.out","w",stdout);
    int a,b,c,m,i;
    scanf("%d%d",&n,&m);
    for(i = 1; i <= m; i++) 
    {
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back({b, c});
    }
 
    dijkstra(1);
 
    for(i = 2; i <= n; i++) 
    {
        if(dmin[i] == INF)
            dmin[i] = 0;
        printf("%d ",dmin[i]);
    }
    return 0;
}
