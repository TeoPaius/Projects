#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream is("1.in");
ofstream os("1.out");

struct Edge{
    int a, b, cost;
    bool operator < (const Edge& e1) const
    {
        return cost > e1.cost;
    }
};

priority_queue<Edge> pr;
Edge auxe;
vector<Edge> sol;

int n, m;
int aux1, aux2, w;
int t[100];
int h[100];

int A, B, W;


void Union(int x, int y);
int Find(int x);

int main()
{
    is >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2 >> w;
        auxe.a = aux1;
        auxe.b = aux2;
        auxe.cost = w;
        pr.push(auxe);
    }

    for(int i = 1; i <= n; ++i)
    {
        t[i] = i;
        h[i] = 1;
    }

    for(int i = 1; i <= m; ++i)
    {
        A = pr.top().a;
        B = pr.top().b;
        W = pr.top().cost;

        if(Find(A) != Find(B))
        {
            sol.push_back(pr.top());
            Union(A,B);
        }

        pr.pop();

    }

    for(const auto& i : sol)
    {
        os << i.a << ' ' << i.b << '\n';
    }

    return 0;
}

int Find(int x)
{
    if(t[x] == x)
        return x;
    return t[x] = Find(t[x]);
}

void Union(int x, int y)
{

    if(h[x] > h[y])
    {
        t[y] = x;
    }
    if (h[y] > h[x])
    {
        t[x] = y;
    }
    if(h[x] == h[y])
    {
        t[x] = y;
        h[x]++;
    }
}
