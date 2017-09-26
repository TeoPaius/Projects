#include <fstream>
#include <vector>
#include <set>

using namespace std;
ifstream is("victorie.in");
ofstream os("victorie.out");

int n, m;
vector<vector<int> > g;
set<int> s;
int aux1, aux2;

void Df(int node);



int main()
{
    is >> n >> m;
    g.resize(n+1);

    for(int i = 1; i <= n; ++i)
    {
        is >> aux1 >> aux2;
        g[aux1].push_back(aux2);
        g[aux2].push_back(aux1);
    }

    is.close();
    os.close();
    return 0;
}

void Df(int node)
{

}
