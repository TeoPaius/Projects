#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 300000
#define MOD 666013

int Q[MAXN], Lv[MAXN], Power[MAXN];
bool Ok[MAXN];
vector<int> G[MAXN];
int i, N, M, K, nr;

void df(int nod, int tata)
{
	Q[++nr] = nod;
	Ok[nod] = true;
	Lv[nod] = Lv[tata] + 1;
	vector<int>::iterator it;
	if (Lv[nod] == 20) return;
	for (it = G[nod].begin(); it != G[nod].end(); ++it){
		if (Ok[*it]) continue;
		df(*it, nod);
		if (nod == i)
			++K;
	}
}

int main()
{
	freopen("clepsidra.in","r",stdin);
	freopen("clepsidra.out","w",stdout);
	
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	Power[0] = 1;
	for (i = 1; i <= N; ++i)
		Power[i] = (Power[i - 1] * 2) % MOD;
	
	for (i = 1; i <= N; ++i){
		K = 0; nr = 0; Lv[i] = 0;
		Ok[i] = true;
		df(i, 0);
		for (int j = 1; j <= nr; ++j)
			Ok[Q[j]] = false;		
		printf("%d\n", (Power[K] + MOD - 2) % MOD);
	}
	
	return 0;
}
	