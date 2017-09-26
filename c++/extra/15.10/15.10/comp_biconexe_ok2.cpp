#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int Dim = 100002;
int N, M;
vector<int> G[Dim];
int T[Dim], niv[Dim], L[Dim];
bool S[Dim];

pair<int, int> ST[Dim], p;
int sp, K;  // stack pointer, nr comp conexe
set<int> comp[Dim]; 


void Dfs(int x)
{
    S[x] = true; 
    L[x] = niv[x];
    for (vector<int>::iterator it = G[x].begin(); it != G[x].end(); ++it)
        if (!S[*it])
        {
            T[*it] = x;
            niv[*it] = niv[x] + 1;
            ST[++sp] = make_pair(x, *it);
 
            Dfs(*it);
 
            if (L[*it] >= niv[x])
            {
                ++K;
                while (true)
                {
                    p = ST[sp--];
                    comp[K].insert(p.first);
                    comp[K].insert(p.second);
 
                    if ( p.first == x && p.second == *it)
                        break;
                }
            }
 
            L[x] = min(L[x], L[*it]);
        }
        else
            if ( *t != T[x] ) // adaugat ulterior
				L[x] = min(L[x], niv[*it]);
}
 
int main()
{
    freopen("biconex.in", "r", stdin);
    freopen("biconex.out", "w", stdout);
 
    scanf("%d %d", &N, &M);
    for (int i = 1, x, y; i <= M; ++i)
    {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
   
	Dfs(1);
 
    printf("%d\n", K);
    for (int i = 1; i <= K; ++i)
    {
        for (auto it = comp[i].begin(); it != comp[i].end(); ++it)
            printf("%d ", *it);
        printf("\n");
    }
}

