#include <stdio.h>
#include <vector>

using namespace std;

#define MOD 666013
#define MAXN 100010

int Nr[MAXN], Sol[MAXN];
vector<int> G[MAXN];
int i,x,y,N;
int F[MAXN], I[MAXN];

inline int Comb(int N, int K)
{
	if (N < K) return 0;
	if (N == K || K == 0) return 1;
	long long aux = 1;
	aux = (aux * F[N]) % MOD;
	aux = (aux * I[K]) % MOD;
	aux = (aux * I[N-K]) % MOD;
	return ( (int) aux);
}

void df(int nod, int tata)
{
	vector<int>::iterator it;
	Nr[nod] = 0;
	for (it=G[nod].begin(); it!=G[nod].end(); ++it){
		if (*it == tata) continue;
		df(*it, nod);
		Nr[nod]+=Nr[*it];
	}
	
	int nr = 0;
	Sol[nod] = 0;
	long long aux = 1LL;
	for (it=G[nod].begin(); it!=G[nod].end(); ++it){
		if (*it == tata) continue;
		aux = (((aux * Sol[*it]) % MOD ) * Comb(Nr[nod]-nr, Nr[*it])) % MOD;
		nr += Nr[*it];
	}
	Sol[nod] = (int) aux;
	Nr[nod] ++;
}

int ridic(int N, int K)
{
	long long aux = 1;
	long long put = N;
	for (int i = 0; (1<<i) <= K; ++i){
		if (K & (1<<i))
			aux = (aux*put) % MOD;
		put = (put*put) % MOD;
	}
	return ( (int) aux);
}

void precalc()
{
	F[0] = I[0] = 1;
	for (int i = 1; i<=N; ++i){
		long long aux = 1LL * F[i-1];
		aux = (aux*i) % MOD;
		F[i] = (int) aux;
		I[i] = ridic(F[i], MOD-2);
	}
}

int main()
{
	freopen("arbore.in","r",stdin);
	freopen("arbore.out","w",stdout);
	
	scanf("%d",&N);
	
	precalc();
	
	for (i=1; i<N; ++i){
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	df(1,0);

	printf("%d\n", Sol[1]);
	
	return 0;
}