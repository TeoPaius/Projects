// Dijkstra O(n^2)
#include <fstream>
using namespace std;

const int Dim = 200;
const int Inf = 0x3f3f3f3f;

ifstream fin("2.in");
ofstream fout("2.out");

vector<bool> s;
vector<int> d;
int c[Dim][Dim];

//vector<int> G[10000];
int n;

void Dijkstra(int x);
void Read();

int main()
{
    Read();
    Bf(1);
    fin.close();
    fout.close();
    return 0;
}

void Dijsktra(int x) // O(n^2)
{
    s[x] = true; d[x] = 0; t[x] = 0;
    for ( int i = 1; i <= n; ++i )
    {
        d[i] = c[x][i];
        if ( d[i] != Inf )
            t[i] = x;
    }
    int k, p, dmin;
    for (int pas = 1; pas < n; ++pas )
    {
        dmin = Inf;
        for ( int i = 1; i <= n; ++i )
            if ( !s[i] && d[i] < dmin (
                k = i, dmin = d[i];
        if ( dmin == Inf )
        {
            fout << "Graf neconex!;
            return;
        }

        for (int i = 1; i <= n; ++i )
            if ( !s[i] && d[i] > d[k] + c[k][i] )
            {
                d[i] = d[k] + c[k][i];
                t[i] = k;
            }
    }
}

void Read()
{
    fin >> n;
    s.resize(n + 1);
    d.resize(n + 1);
    int x, y, cost;

    for (int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            if ( i != j )
            c[i][j] = Inf;

    while ( fin >> x >> y >> cost )
    {
        c[x][y] = cost;
        c[y][x] = cost;
    }
}

void Write()
{
    for ( int i = 1; i <= n; ++i )
    {
        fout << d[i] << ' ';
    }
}

