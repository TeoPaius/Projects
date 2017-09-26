#include <fstream>
#include <queue>

using namespace std;
ifstream is("bfs.in");
ofstream os("bfs.out");

int n, m; // noduri muchii
int g[100][100]; // graful
bool viz[100]; // nod vizitat sau nu
int aux1, aux2;
queue<int> q;
int nod;

void Bfs();

int main()
{
    is >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        is >> aux1 >> aux2;
        g[aux1][aux2] = 1;
        g[aux2][aux1] = 1;
    }

    q.push(1);
    viz[1] = true; // pui primul nod

    Bfs();

    is.close();
    os.close();
    return 0;
}

void Bfs()
{
    while(!q.empty())
    {
        nod = q.front(); // tot iei din coada
        q.pop();

        for(int i = 1; i <= n; ++i)
        {
            if(i != nod && !viz[i] && g[i][nod] == 1) //verifici care-s vecini care nu au fost vizitati inca
            {
                q.push(i); // adaugi in coada
                viz[i] = true;
            }
        }
    }

}
