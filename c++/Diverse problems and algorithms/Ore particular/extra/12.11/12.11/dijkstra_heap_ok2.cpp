// ok -infoarena
#include <fstream>
#include <vector>
using namespace std;
 
const int Dim = 50010;
const int Inf = 0x3f3f3f3f;
 
vector<pair<int, int>> G[Dim];
int D[Dim], P[Dim], H[Dim];
 
int n, m, nH, x, y, w, k, aux, c, inHeap;
 
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

void Swap(int p, int s);
void pop();
void push(int x);
void Up(int poz);

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
 
    push(1);
    while ( nH ) 
    {
        k = H[1];
        pop();
 
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
					push(x);
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

void Swap(int p, int s)
{
	swap(H[p], H[s]);
	P[H[p]] = p;
	P[H[s]] = s;
}

void pop() 
{
    H[1] = H[nH--];
    P[H[1]] = 1;
 
    int p = 1, s = 2; // parent, son      // Down Heap
    while (s <= nH) 
    {
        if ( s + 1 <= nH && D[H[s + 1]] < D[H[s]])
            s++;
 
        if (D[H[p]] > D[H[s]]) 
        {
			Swap(s, p);
            p = s;
            s = 2 * p;
        } else
            break;
    }
}

void push(int node)
{
     H[++nH] = node;
     P[node] = nH;
     Up(nH);
}
 
void Up(int poz)  // cand poz == ++nH s-e poate insera un element nou
{
    int s = poz, p = s / 2; // son, parent
    while (p != 0 && D[H[s]] < D[H[p]]) 
    {
		Swap(p, s);
        s = p;
        p = s / 2;
    }
}
 
 
 
 
 
