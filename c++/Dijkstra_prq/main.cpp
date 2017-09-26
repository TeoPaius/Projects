#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

ifstream is("1.in");
ofstream os("1.out");

#define Inf 0x3f3f3f3f

int n, m;
vector<vector<pair<int, int> > > G;
set<pair<int, int> > s;
int d[100];
int node, cost;

int aux1, aux2 , aux3;
int main()
{
    is >> n >> m;
    G.resize(n+1);
    for(int i = 2; i <= n; ++i)
        d[i] = Inf;



    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2 >> aux3;
        G[aux1].push_back({aux2, aux3});
        G[aux2].push_back({aux1, aux3});
    }

    s.insert({1,0});

    while(!s.empty())
    {
        node = s.begin()->first;
        cost = s.begin()->second;
        s.erase(s.begin());

        for(const auto& i : G[node])
        {
            if(d[i.first] > d[node] + i.second)
            {
                d[i.first] = d[node] + i.second;
                s.insert(i);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        os << d[i] << ' ';
    }
    is.close();
    os.close();
    return 0;
}
