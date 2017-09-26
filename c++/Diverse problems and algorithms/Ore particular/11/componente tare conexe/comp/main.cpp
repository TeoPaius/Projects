#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream is("comp.in");
ofstream os("comp.out");

vector<vector<int> > G;
int n, m;
int aux1, aux2;
bool sel[100];
int niv_min[100];
int niv[100];
stack<int> stk;
bool ok[100]; // daca e sau nu in stiva

vector<int> auxv;
vector<vector<int> > sol;


void Df(int nod, int nv);
void Write();

int main()
{
    is >> n >> m;
    G.resize(n+1);
    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2;
        G[aux1].push_back(aux2);
    }

    for(int i = 1; i <= n; ++i)
        if(!sel[i])
        {
            Df(i, 0);
        }
    Write();

    is.close();
    os.close();
    return 0;
}

void Df(int nod, int nv)
{
    niv[nod] = niv_min[nod] = nv;
    stk.push(nod);
    sel[nod] = true;
    ok[nod] = true;
    for(auto x : G[nod])
    {
        if(!sel[x])
        {
            Df(x, nv + 1);
            niv_min[nod] = min(niv_min[nod], niv_min[x]);
        }
        else
            if(ok[x])
                niv_min[nod] = min(niv_min[nod], niv_min[x]);

    }
    if(niv_min[nod] == niv[nod])
    {
        auxv.clear();
        do
        {
            aux1 = stk.top();
            ok[aux1] = false;
            stk.pop();
            auxv.push_back(aux1);
        }while(aux1 != nod);
        sol.push_back(auxv);
    }
}

void Write()
{
    os << sol.size() << '\n';
    for(auto v : sol)
    {
        for(auto x : v)
        {
            os << x << ' ';
        }
        os << '\n';
    }
}
