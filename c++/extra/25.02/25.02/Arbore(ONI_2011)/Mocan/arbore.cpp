#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int mod = 666013;
const int maxN = 100100;

int N;
vector <int> G[maxN];
bool viz[maxN];
int nrNodJos[maxN], D[maxN];
int fact[maxN];

inline int putere(int N, int P) {
	int aux;
	if (P == 0)
		return 1;
	if (P == 1)
		return (N % mod);
	
	if (P % 2 == 0) {
		aux = putere(N, P / 2);
		return ((1LL * aux * aux) % mod);
	}
	else {
		aux = putere(N, P - 1);
		return ((1LL * aux * N) % mod);
	}
}

inline int comb(int N, int K) {
	int ret = fact[N];

	ret = (1LL * ret * putere(fact[K], mod - 2)) % mod;
	ret = (1LL * ret * putere(fact[N - K], mod - 2)) % mod;

	return ret;
}


inline void dfs(int nod) {
	int i, fiu;

	viz[nod] = 1;
	nrNodJos[nod] = 1;

	for (i = 0; i < G[nod].size(); i++) {
		fiu = G[nod][i];
		if (!viz[fiu]) {
			dfs(fiu);
			nrNodJos[nod] += nrNodJos[fiu];
		}
	}
}

inline void solve(int nod) {
	int i, fiu, total = nrNodJos[nod] - 1;

	viz[nod] = 1;
	D[nod] = 1;

	for (i = 0; i < G[nod].size(); i++) {
		fiu = G[nod][i];
		if (!viz[fiu]) {
			solve(fiu);
			D[nod] = (1LL * D[nod] * D[fiu]) % mod;
			D[nod] = (1LL * D[nod] * comb(total, nrNodJos[fiu])) % mod;
			total -= nrNodJos[fiu];
		}
	}
}

int main() {
	int i, a, b;

	freopen("arbore.in", "r", stdin);
	freopen("arbore.out", "w", stdout);

	fact[0] = 1;
	for (i = 1; i < maxN; i++)
		fact[i] = (1LL * fact[i - 1] * i) % mod;

	scanf("%d", &N);

	for (i = 1; i < N; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1);

	memset(viz, 0, sizeof(viz));
	solve(1);

	printf("%d\n", D[1]);

	return 0;
}
