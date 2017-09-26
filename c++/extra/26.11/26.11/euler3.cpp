// OK infoarena
// Ciclu eulerian - O(N + M)
#include <fstream>
#include <bitset>
#include <vector>

#define Nmax 100009
#define Mmax 500009
#define pb push_back
#define x first
#define y second
using namespace std;

ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");

typedef pair<int,int> PP;

int N,M,x,y;
vector<int> G[Nmax], Cycle;
PP E[Mmax];
bitset<Mmax> viz;
 
int IsEulerian()
{
     for(int i = 1; i <= N; ++i)
          if(G[i].size() & 1) return 0;
     return 1;
}
 
void DFS(int node)
{
	for(vector<int>::iterator it = G[node].begin(); it != G[node].end(); ++it)
		if (!viz[*it])           // *it e muchia incidenta la node
		{
			viz[*it] = 1;           // selectez muchia *i
			DFS(E[*it].x + E[*it].y - node); // ca nu stiu care dintre x sau y e node
		}
    Cycle.pb(node);
}
 
int main()
{
	f >> N >> M;
	for(int i = 1; i <= M; ++i)
	{
        f >> x >> y; 
        G[x].pb(i) , G[y].pb(i);      // G[x] retine muchiile in care apare x
        E[i] = PP(x, y);              // E[i] retine muchia i a grafului ca pair<x, y> 
	}
    
    if(IsEulerian())
    {
        DFS(1);
        for(size_t i = 0; i < Cycle.size() - 1; ++i)
            g << Cycle[i] << ' ';
        g << '\n';
     }
     else g << -1 << '\n';
     
     f.close();
     g.close();
     return 0;
}
