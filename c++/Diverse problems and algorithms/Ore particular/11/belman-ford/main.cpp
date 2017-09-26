#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define Inf 0x3f3f3f

ifstream is("bellmanford.in");
ofstream os("bellmanford.out");

int n, m;

struct Edge{
    int v;
    int cost;
};

vector<vector<Edge> > G;
int d[55000];
int t[55000];
queue<int> q;
bool ok[55000];
int cnt[55000];
Edge aux;
int x;


int main()
{

    is >> n >> m;
    G.resize(m+1);
    for(int i = 1; i <= n; ++i)
        d[i] = Inf;
    for(int i = 1; i <= m; ++i)
    {
        is >> x >> aux.v >> aux.cost;
        G[x].push_back(aux);
    }
    q.push(1);
    d[1] = 0;
    ok[1] = true;

    while(!q.empty())
    {
        x = q.front();
        q.pop();
        ok[x] = false;
        for(vector<Edge>::iterator it = G[x].begin(); it != G[x].end(); ++it)
        {
            int y = it->v;
            int z = it->cost;
            if(d[y] > d[x] + z)
            {
                d[y] = d[x] + z;
                if(!ok[y])
                {
                    cnt[y]++;
                    if(cnt[y] == n)
                    {
                        os << "Ciclu negativ!";
                        return 0;
                    }
                    q.push(y);
                    ok[y] = true;
                }
            }
        }

    }
    for(int i = 2; i <= n; ++i)
        os << d[i] << ' ';
    is.close();
    os.close();
    return 0;
}

