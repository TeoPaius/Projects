#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream is("prim.in");
ofstream os("prim.out");

struct Edge{
    int a, b, c;
    bool operator < (const Edge& e) const
    {
        return c > e.c;
    }
};

vector< pair<int, int> > e;
vector<vector<int> > G;
int aux1, aux2, aux3;
priority_queue<Edge> q;
vector<Edge > sol;
bool inapm[100];
int n, m;
bool sel[100];
int t[100];
int cost[100][100];
int cnt;
int minim = 0x3f3f3f3f;
int cnode = 1;
Edge emin;
Edge eaux;


int main()
{
    is >> n >> m;
    G.resize(n+1);
    emin.c = 0x3f3f3f3f;
    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2 >> aux3;
        G[aux1].push_back(aux2);
        G[aux2].push_back(aux1);
        cost[aux1][aux2] = aux3;
        cost[aux2][aux1] = aux3;
    }


    for(auto i : G[1])
    {
        eaux.a = 1;
        eaux.b = i;
        eaux.c = cost[1][i];
        if(eaux.c < emin.c)
            emin = eaux;
        q.push(eaux);
    }

    inapm[emin.a] = true;

    q.push(emin);

    Edge New;
    while(cnt < n)
    {
        eaux = q.top();
        q.pop();
        if(inapm[eaux.a] && inapm[eaux.b])
            continue;
        else
        {
            if(inapm[eaux.a] && !inapm[eaux.b])
                switch(eaux.a, eaux.b);
            for(auto i : G[eaux.a])
            {
                if(!inapm[i])
                {
                    New.a = eaux.a;
                    New.b = i;
                    New.c = cost[eaux.a][i];
                    q.push(New);
                    inapm[i] = true;
                }
            }
            sol.push_back(eaux);
            cnt++;
        }
    }

    for(auto i : sol)
    {
        os << i.a << ' ' << i.b << '\n';
    }

    is.close();
    os.close();
    return 0;
}
