#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
 
#define DIM 50010
#define INF 1000000000
 
using namespace std;
ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");
 
vector<pair<int, int> > G[DIM];
queue<int> q;
bitset<DIM> v;
int D[DIM], N[DIM];
 
int n, m, x, y, z;
 
int main() 
{
    fin >> n >> m;
    for (int i = 1;i <= m; i++) 
    {
        fin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
    }
 
    q.push(1);
    v[1] = 1;
    D[1] = 0;
    for (int i = 2; i <=n; i++)
        D[i] = INF;
 
    while ( !q.empty() ) 
    {
        x = q.front();
        q.pop();
        v[x] = 0;
 
        for (int i = 0; i < G[x].size(); i++) 
        {
            y = G[x][i].first;
            if (D[y] > D[x] + G[x][i].second) 
            {
                D[y] = D[x] + G[x][i].second;
                if (!v[y]) 
                {
                    N[y]++;
                    if (N[y] == n) 
                    {
                        fout<<"Ciclu negativ!";
                        return 0;
                    }
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
 
    for (int i = 2; i <= n; i++)
        fout << D[i] << " ";
 
    return 0;
}
