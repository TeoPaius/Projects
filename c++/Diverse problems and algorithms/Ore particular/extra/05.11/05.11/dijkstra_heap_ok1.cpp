// ok - infoarena
#include <fstream>
#include <vector>
using namespace std;
 
const int Dim = 50010;
const int Inf = 0x3f3f3f3f;

 
vector<pair<int, int>> G[Dim];
int D[Dim], V[Dim], P[Dim], H[Dim];
 
int n, m, nH, x, y, w, k, aux, c, inHeap;
 
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
 
void pop() 
{
    H[1] = H[nH--];
    P[H[1]] = 1;
 
    int p = 1, c = 2;
    while (c <= nH) 
    {
        if ( c + 1 <= nH && D[H[c + 1]] < D[H[c]])
            c++;
 
        if (D[H[p]] > D[H[c]]) 
        {
            aux = H[p];
            H[p] = H[c];
            H[c] = aux;
            P[H[p]] = p;
            P[H[c]] = c;
            p = c;
            c = 2 * p;
        } else
            break;
    }
}
 
void Up(int poz) 
{
    int c = poz, p = c / 2; // curent, parinte
    while (p != 0 && D[H[c]] < D[H[p]]) 
    {
        aux = H[c];
        H[c] = H[p];
        H[p] = aux;
        P[H[p]] = p;
        P[H[c]] = c;
        c = p;
        p = c/2;
    }
}
 
int main() 
{
    fin >> n >> m;
    for (int i = 1; i <= m; i++) 
    {
        fin >> x >> y >> c;
        G[x].push_back({y, c});
    }
 
    for (int i = 1; i <= n;i++)
        D[i] = Inf;
    D[1] = 0;
 
    H[1] = 1;
    P[1] = 1;
    nH = 1;
    while ( nH ) 
    {
        k = H[1];
        pop();
        V[k] = 1;
 
        for (const auto& p : G[k]) 
        {
            x = p.first; w = p.second;
            if (D[x] > D[k] + w) 
            {
                inHeap = (D[x] != Inf);
                D[x] = D[k] + w;
                if (inHeap)
                    Up( P[x] );
                else 
                {
                    nH++;
                    H[nH] = x;
                    P[x] = nH;
                    Up(nH);
                }
            }
        }
    }
 
    for (int i = 2; i <= n; i++)
        if (D[i] == Inf)
            fout << "0 ";
        else
            fout << D[i] << " ";
 
    return 0;
}
