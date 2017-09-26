// O(n + m)
#include <fstream>
#include <vector>
#include <stack>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("ctc.in");
ofstream os("ctc.out");

int n, m, a, b;
int idx;
vector<vector<int> > G, cc;
vector<int> index, L, c;
vector<bool> inStack;
stack<int> stk;

void Tarjan(int nod);

int main()
{
    is >> n >> m;
    
    G.resize(n + 1);
    index.resize(n + 1, INF);
    L.resize(n + 1);
    inStack.resize(n + 1);
    
    for ( int i = 1; i <= m; ++i )
    {
        is >> a >> b;
        G[a].push_back(b);
    }
    
    for ( int i = 1; i <= n; ++i )
    {
        if ( index[i] == INF )
            Tarjan(i);
    }
    
    os << c.size() << "\n";
  
    for ( size_t i = 0; i < cc.size(); ++i )
    {
        for ( size_t j = 0; j < cc[i].size(); ++j )
            os << cc[i][j] << " ";
        os << "\n";
    }
    
    is.close();
    os.close();
    return 0;
}

void Tarjan(int nod)
{
    index[nod] = L[nod] = idx++;
    stk.push(nod);
    inStack[nod] = true;
    for ( vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); ++it )
        if ( index[*it] == INF ) // muchie de arbore
        {
            Tarjan(*it);
            L[nod] = min(L[nod], L[*it]);
        }
        else  // muchie de intoarcere
            if ( inStack[*it] )
                L[nod] = min(L[nod], index[*it]);
    
    if ( index[nod] == L[nod] )
    {
        c.clear();
        int nod2;
        do
        {
            c.push_back(nod2 = stk.top());
            stk.pop();
            inStack[nod2] = false;
        } while ( nod2 != nod );
        cc.push_back(c);
    }
}
