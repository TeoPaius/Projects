// OK infoarena
// Ciclu eulerian - O(N + M)
#include <fstream>
#include <bitset>
#include <vector>

#define Nmax 100009
#define Mmax 500009
#define pb push_back
using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

struct Edge { 
	int x, y; 
};

int N,M,x,y;
vector<int> G[Nmax], Cycle;
Edge E[Mmax];
bitset<Mmax> viz;
 
int IsEulerian()
{
     for(int i = 1; i <= N; ++i)
          if(G[i].size() & 1) return 0;
     return 1;
}

#define e (G[node].back()) 

inline void DFS(int node)         // inline - important!!!
{
	while (G[node].size() )
	{
		if ( viz[e] )
		{
			G[node].pop_back();
			continue;
		}
		viz[e] = 1;           // selectez muchia e
		DFS(E[e].x + E[e].y - node); // pentru ca nu stiu care dintre x sau y e node
	}
    Cycle.pb(node);
}
 
int main()
{
	fin >> N >> M;
	for(int i = 1; i <= M; ++i)
	{
        fin >> x >> y; 
        G[x].pb(i) , G[y].pb(i);      // G[x] retine muchiile in care apare x
        E[i] = {x, y};              // E[i] retine muchia i a grafului ca pair<x, y> 
	}
    
    if(IsEulerian())
    {
        DFS(1);
        for(size_t i = 0; i < Cycle.size() - 1; ++i)
            fout << Cycle[i] << ' ';
        fout << '\n';
     }
     else fout << -1 << '\n';
     
     fout.close();
     fin.close();
     return 0;
}

