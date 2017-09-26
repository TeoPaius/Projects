#include <fstream>
#include <queue>
using namespace std;

ifstream fin("1.in");
ofstream fout("1.out");

vector<bool> s;
vector<int> d, t;
vector<vector<int>> G;
//vector<int> G[10000];
int n;

void Bf(int x);
void Read();
void Show(int k);

int main()
{
    Read();
    Bf(1);

    fout << d[9] << "\n";
    Show(9);
    fin.close();
    fout.close();
    return 0;
}

void Show(int k)
{
    if ( !k )
        return;
    Show(t[k]);
    fout << k << " ";
}

void Read()
{
    fin >> n;
    G.resize(n + 1);
    s.resize(n + 1);
    d.resize(n + 1);
    t.resize(n + 1);
    int x, y;
    while ( fin >> x >> y )
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void Bf(int x)
{
    queue<int> Q;
    Q.push(x); s[x] = true;
  //  fout << x << ' ';
    int i;
    while ( !Q.empty() )
    {
        i = Q.front(); Q.pop();
        for ( vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it )
        {
            if ( s[*it] ) continue;
            Q.push(*it);
            s[*it] = true;
            d[*it] = d[i] + 1;
            t[*it] = i;
      //      fout << *it << ' ';
        }
    }
}

