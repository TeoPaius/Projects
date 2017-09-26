#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream is("prim.in");
ofstream os("prim.out");

struct Edge{
    int a;
    int b;
    int cost;
    bool operator < (const Edge& other) const
    {
        return cost > other.cost;
    }

};

int n, m;
vector<vector<Edge> > G;
priority_queue<Edge> q;
int aux1, aux2, aux3;
int w[100][100];
bool inapm[100];
vector<Edge> apm;
Edge aux;
int cnt = 1;

void Prim();

int main()
{
    is >> n >> m;
    G.resize(n+1);

    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2 >> aux3;
        aux.a = aux1;
        aux.b = aux2;
        aux.cost = aux3;
        G[aux1].push_back(aux);
        swap(aux.a, aux.b);
        G[aux2].push_back(aux);
        w[aux1][aux2] = aux3;
        w[aux2][aux1] = aux3;
    }

    inapm[1] = true;
    for(const auto& i : G[1])
    {
        q.push(i);
    }

    Prim();

    for(const auto& i : apm)
    {
        os << i.a << ' ' << i.b << '\n';
    }

    is.close();
    os.close();
    return 0;
}

void Prim()
{
    Edge e;
    while(cnt < n)
    {
        e = q.top();
        q.pop();
        apm.push_back(e);
        inapm[e.b] = true;
        cnt++;
        for(const auto& i : G[e.b])
        {
            if(!inapm[i.b])
            {
                q.push(i);
            }

        }
    }


}
