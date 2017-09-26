// ok infoarena
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;

struct Edge {
	int a, b;
};

const int MaxE = 500002, MaxN = 100002;
vector<int> G[MaxN];
int D[MaxN], p[MaxN], n, m;
Edge E[MaxE];
bool sel[MaxE];
int stk[MaxE], C[MaxE];
 
int main()
{
    freopen("ciclueuler.in", "r", stdin);
    freopen("ciclueuler.out", "w", stdout);
	int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &a, &b);
        E[i].a = a, E[i].b = b;
        G[a].push_back(i);  // retin numarul de ordine a muchiilor nodului E1[i]
        G[b].push_back(i);
        ++D[a];  ++D[b];
    }
    
    for (int i = 1; i <= n; ++i)
        if (D[i] % 2 == 1)
        {
            printf("-1\n");
            return 0;
        }
        
	int e, x;
    stk[++stk[0]] = 1;
    while (stk[stk[0]])
    {
        x = stk[stk[0]];
        if (p[x] < int(G[x].size())) // p[x] - pozitie curenta (iterator) pentru G[x]
        {
            for (; p[x] < int(G[x].size()); ++p[x])
            {
				e = G[x][p[x]];
                if (sel[e]) continue; // nu e vizitata aceasta muchie incidenta cu x
                
                if (E[e].a == x)           // daca primul capat al muchiei e chiar nodul x
					stk[++stk[0]] = E[e].b;  // punem celalalt capat (nod) in stiva   
				else
					stk[++stk[0]] = E[e].a;
					sel[e] = true;
					
				++p[x];
				break;
			}
        }
        else
        {
            C[++C[0]] = stk[stk[0]]; // pop cand nu mai are vecini
            --stk[0];
        }
    }
 
    if (C[0] != m + 1)
    {
        printf("-1\n");
        return 0;
    }
 
    for (int i = C[0]; i >= 2; --i)
        printf("%d ", C[i]);
    printf("\n");
}
