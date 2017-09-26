#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream is("djk.in");
ofstream os("djk.out");

vector<vector<int> > G;
set<int> s;
int n, m;
int w[100][100];
int d[100];
int aux1, aux2, aux3;

void Djk();

int main()
{
    is >> n >> m;
    G.resize(n+1);
    for(int i = 1; i <= n; ++i)
        d[i] = 0x3f3f3f3f;

    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2 >> aux3;
        G[aux1].push_back(aux2);
        w[aux1][aux2] = aux3;
    }

    s.insert(1);
    d[1] = 0;

    Djk();

    for(int i = 1; i <= n; ++i)
        os << d[i] << ' ';

    is.close();
    os.close();
    return 0;
}

void Djk()
{
    int nod;
    while(!s.empty())
    {
        nod = *(s.begin());
        s.erase(s.begin());
        for(const auto& i : G[nod])
        {
            if(d[i] > d[nod] + w[nod][i])
            {
                d[i] = d[nod] + w[nod][i];
                s.insert(i);
            }
        }

    }


}
