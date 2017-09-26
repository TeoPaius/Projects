#include <fstream>
#include <iostream>
#include <iomanip>
#define DIM 1001
#define MAX 51
#define INF 32000
using namespace std;

int t[MAX][DIM]; // t[i][j] = timpul minim in care se efectueaza deplasarea
                 // de la 1 la i si bateria mai are j W
int p[MAX];      // sir caracteristic
int m, n, K;
int W[MAX][MAX], T[MAX][MAX]; // matricile costurilor in energie si timp ale muchiilor
int tmin, wmin;
int c[DIM*50][2];   // cu < 50 nu mai merge (in BC 3.1 nu se poate aloca static atat)
int prim, ultim;

void Read();
void Cbin();
int Lee(int x);
void Write();

ofstream fout("lanterna.out");

int main()
{
    Read();
    tmin = Lee(K);
 //   cout << tmin; cin.get();
    wmin = K;
    Cbin();
    Write();

    fout.close();
    return 0;
}

void Read()
{
    ifstream fin("lanterna.in");
    int i;
    fin >> n >> K;
    for (i = 1; i <= n; i++)
        fin >> p[i];
    int a, b, timp, w;
    fin >> m;
    int j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            /*if (i != j) */T[i][j] = W[i][j] = INF;
    for (i = 1; i <= m; i++)
    {
        fin >> a >> b >> timp >> w;
        T[a][b] = T[b][a] = timp;
        W[a][b] = W[b][a] = w;
    }
    fin.close();
}

int Lee(int x) // x valoarea nominala a bateriei (incaracta)
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= x; j++)
            t[i][j] = INF;
    t[1][x] = 0;
    prim = ultim = 0;
    c[prim][0] = 1;
    c[prim][1] = x;
    while (prim <= ultim)
    {
        int i = c[prim][0];
        int e = c[prim][1];
    //  cout << " i = " << i <<" e = " << e; cin.get();
        for (int j = 1; j <= n; j++)
        {
            if (e < W[i][j]) continue;
            int z;
            if (p[j]) z = x;
            else      z = e - W[i][j];
            if (t[i][e] + T[i][j] < t[j][z])
            {
                t[j][z] = t[i][e] + T[i][j];
                c[++ultim][0] = j;
                c[ultim][1] = z;
            }
        }
        prim++;
    }
    int timpm = INF;
    for (i = 0; i <= x; i++)
        if (timpm > t[n][i]) timpm = t[n][i];

    return timpm;
}

void Cbin()
{
    int l = 1, r = K;
    while ( l <= r )
    {
        int mijl = (l + r)/2;
        int timp = Lee(mijl);
  //      cout << timp << " " << mijl << " " << l << " " << r; cin.get();
        if (timp > tmin)  l = mijl + 1;
        else
             if ( timp == tmin )
             {
                wmin = mijl;
                r = mijl - 1;
             }
    }
}

void Write()
{
    fout << tmin << " " << wmin << "\n";
}
