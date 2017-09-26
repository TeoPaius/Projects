// ok infoarena
#include <fstream>
#include <vector>
using namespace std;
 
const int MAX_N = 100002;
 
int N, M, nr;
int E[2 * MAX_N], niv[2 * MAX_N], pos[MAX_N], log2[2 * MAX_N], r[2 * MAX_N][20];
vector < int > v[MAX_N];
 
void DFS(int x, int nv) 
{
    ++nr;
    E[nr] = x, niv[nr] = nv, pos[x] = nr;
    for(int i = 0; i < (int) v[x].size(); ++i) 
    {
        DFS(v[x][i], nv + 1);
        ++nr;
        E[nr] = x, niv[nr] = nv;
    }
}
 
void RMQ() 
{
    int n = 2 * N - 1; 
    for(int i = 1; i <= n; ++i)
        r[i][0] = i;
 
    for(int j = 1; (1 << j) <= n; ++j)
        for(int i = 1; i + (1 << j) - 1 <= n; ++i) 
        {
            if (niv[r[i][j - 1]] < niv[r[i + (1 << (j - 1))][j - 1]])
                r[i][j] = r[i][j - 1];
            else 
				r[i][j] = r[i + (1 << (j - 1))][j - 1];
        }
}
 
int LCA(int x, int y) 
{
    x = pos[x], y = pos[y];
 
    if(x > y)
        swap(x, y); 
    int k = log2[y - x  + 1];   // pe infoarena e ok si cu log2[y - x]
 
    if(niv[r[x][k]] < niv[r[y - (1 << k) + 1][k]])
        return E[r[x][k]];
    return E[r[y - (1 << k) + 1][k]];
}
 
int main() {
    ifstream f("lca.in");
    ofstream g("lca.out");
 
    f >> N >> M;
    for(int i = 2, x; i <= N; ++i) 
    {
        f >> x;
        v[x].push_back(i);
    }
 
    for(int i = 2; i < 2 * MAX_N; ++i)
        log2[i] = log2[i / 2] + 1;
 
    DFS(1, 1);
    RMQ();
 
    for(int i = 1, x, y; i <= M; ++i) {
        f >> x >> y;
        g << LCA(x, y) << "\n";
    }
 
    f.close();
    g.close();
 
    return 0;
}
