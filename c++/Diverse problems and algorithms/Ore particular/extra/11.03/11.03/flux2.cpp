// OK infoarena
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <bitset>
#include <queue>
 
using namespace std;
 
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
 
const int MaxN = 1005;
const int Inf = 0x3f3f3f3f;
 
int n, m, C[MaxN][MaxN], t[MaxN];
vector<int> G[MaxN];
bitset<MaxN> v;
queue <int> Q;
 
inline bool Bf(int source, int sink) 
{
    v.reset();
    v[source] = 1;
    Q.push(source);
    while (!Q.empty()) 
    {
        int x = Q.front();
        Q.pop();
        if (x == sink)
            continue;
        for (const auto& y : G[x]) 
            if (!v[y] && C[x][y] > 0) 
            {
                v[y] = 1;
                t[y] = x;
                Q.push(y);
            }
    }
    return v[sink];
}
 
inline int MaxFlow(int source, int sink) 
{
    int maxflow = 0, fmin;
   
    while (Bf(source, sink) )
        for (const auto& x : G[sink]) 
        {
            if (!v[x] || C[x][sink] <= 0)
                continue;
            
            t[sink] = x;
            fmin = Inf;
            for (int i = sink ; i != source ; i = t[i])
                fmin = min(fmin, C[t[i]][i]);  // C - capacitate reziduala
            
            if (!fmin)  continue;

            for (int i = sink ; i != source ; i = t[i]) 
            {
                C[t[i]][i] -= fmin;
                C[i][t[i]] += fmin;
            }
            maxflow += fmin;
        }
    return maxflow;
}
 
int main() 
{
	int x, y, c;
    fin >> n >> m;
    for (int i = 1 ; i <= m ; ++i) 
    {
        fin >> x >> y >> c;
        G[x].push_back(y);
        G[y].push_back(x);
        C[x][y] += c;
    }
    
    fout << MaxFlow(1, n) << '\n';
    
    fin.close();
    fout.close();
}
