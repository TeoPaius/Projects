#include <fstream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
 
ifstream fin ("biconex.in");
ofstream fout ("biconex.out");
 
const int Dim = 1e5 + 5;
 
 
int m, n, K;     // K - nr comp biconexe
vector <int> G[Dim];
int niv[Dim], L[Dim];
stack <pair<int, int> > s;
set<int> comp[Dim];
 
vector<vector<int>> comp;
void Extract(int x, int y) 
{
	vector<int> c;
    int xs, ys;
    do 
    {
        xs = s.top().first; ys = s.top().second;
        c.push_back(xs);
        c.push_back(ys);
        
        comp[K].insert (xs);
        comp[K].insert (ys);
        s.pop();
    } while (xs != x || ys != y);
    comp.push_back(c);
}
 
void Dfs(int x, int tata, int nv) 
{
    L[x] = niv[x] = nv;
    for (vector <int> :: iterator it = G[x].begin(); it != G[x].end(); ++it) 
    {
        if (*it == tata)
            continue;
        if (!niv[*it])  // fiu nevizitat
        {
            s.push (make_pair (x, *it));
            Dfs (*it, x, nv + 1);
            L[x] = min(L[x], L[*it]);
            if (L[*it] >= niv[x])
                K++, Extract(x, *it);
        }
        else
            L[x] = min(L[x], niv[*it]);
    }
}
 
int main() 
{
    fin >> n >> m;
    for (int x, y, i = 0; i < m; ++i) 
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    Dfs (1, 0, 1);
    fout << K << "\n";
    for (int i = 0; i < K; ++i) 
    {
        for (set <int>::iterator it = comp[i].begin(); it != comp[i].end(); ++it)
            fout << *it << " ";
        fout << "\n";
    }
}
