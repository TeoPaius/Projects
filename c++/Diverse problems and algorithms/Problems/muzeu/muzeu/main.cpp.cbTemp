#include <fstream>
#include <queue>
#include <iomanip>
using namespace std;
ifstream is ("muzeu.in");
ofstream os ("muzeu.out");

struct Cell{
    int i, j;
};

void Lee();
void Modif(int i, int j);

int n;
char a[253][253];
int sol[253][253];
queue<Cell> q;
Cell aux;

int main()
{
    is >> n;
    for(int i = 0; i <= n + 1; ++i)
    {
        sol[0][i] = -2;
        sol[i][0] = -2;
        sol[n+1][i] = -2;
        sol[i][n+1] = -2;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            is >> a[i][j];
            if(a[i][j] == '#')
                sol[i][j] = -2;
            if(a[i][j] == 'P')
            {
                aux.i = i;
                aux.j = j;
                q.push(aux);
            }
        }
    Lee();

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(sol[i][j] == 0 && a[i][j] != 'P')
                sol[i][j] = -1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            os << sol[i][j] <<' ';
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}

void Lee()
{
    while(q.size())
    {
        Modif(q.front().i, q.front().j);
        q.pop();
    }
}

void Modif(int i, int j)
{
    if(sol[i-1][j] == 0 && a[i-1][j] != 'P')
    {
        sol[i-1][j] = sol[i][j] + 1;
        aux.i = i-1;
        aux.j = j;
        q.push(aux);
    }
    if(sol[i][j+1] == 0 && a[i][j+1] != 'P')
    {
        sol[i][j+1] = sol[i][j] + 1;
        aux.i = i;
        aux.j = j+1;
        q.push(aux);
    }
    if(sol[i+1][j] == 0 && a[i+1][j] != 'P')
    {
        sol[i+1][j] = sol[i][j] + 1;
        aux.i = i+1;
        aux.j = j;
        q.push(aux);
    }
    if(sol[i][j-1] == 0 && a[i][j-1] != 'P')
    {
        sol[i][j-1] = sol[i][j] + 1;
        aux.i = i;
        aux.j = j-1;
        q.push(aux);
    }
}

