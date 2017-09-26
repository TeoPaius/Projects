#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 300010
#define MOD 666013

vector<int> G[MAXN];
int D[MAXN], Lv[MAXN], Ans[MAXN], Power[MAXN];
bool Ok[MAXN];
int N, M;

void df(int nod, int tata)
{
	Ok[nod] = true;
	Lv[nod] = Lv[tata] + 1;
	int nr = 1;
	if (nod == 1) nr = 0;
	D[nod] = Lv[nod];
	for (vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); ++it){
		int nod2 = *it;
		if (nod2 == tata) continue;
		if (Ok[nod2]) {
			D[nod] = min(D[nod], Lv[nod2]);
			continue;
		}
		df(nod2, nod);
		if (D[nod2] >= Lv[nod])
			++nr;
		D[nod] = min(D[nod2], D[nod]);
	}
	Ans[nod] = Power[nr];
}
int main()
{
	freopen("clepsidra.in","r",stdin);
	freopen("clepsidra.out","w",stdout);
	
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	Power[0] = 1; 
	for (int i = 1; i <= N; ++i)
		Power[i] = (Power[i - 1] * 2) % MOD;
	for (int i = 1; i <= N; ++i)
		Power[i] = (Power[i] + MOD - 2) % MOD;
	
	df(1, 0);
	
	for (int i = 1; i <= N; ++i)
		printf("%d\n", Ans[i]);
	return 0;
}