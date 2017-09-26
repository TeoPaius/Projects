#include <stdio.h>
#include <vector>
using namespace std;

#define MOD 666013
#define MAXN 100010

int N, K;
int F[MAXN], I[MAXN];

void Precalc();
int Comb(int N, int K);

int main()
{
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
	scanf("%d",&N, &K);

	Precalc();
    printf("%d", Comb(N, K));

	return 0;
}

long long Ridic(long long x,long long n)
{
	if(n == 1)
		return x;
	long long  res = Ridic(x, n / 2);
	res = (res * res )% MOD;
	if( res % 2 == 1)
        res = (res * x) % MOD;

	return res;
}

int Comb(int N, int K)
{
	if (N < K) return 0;
	if (N == K || K == 0) return 1;
	long long aux = 1;
	aux = (aux * F[N]) % MOD;
	aux = (aux * I[K]) % MOD;
	aux = (aux * I[N-K]) % MOD;
	return ( (int) aux);
}

void Precalc()
{
	F[0] = I[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		F[i] = (int)(1LL * F[i-1] * i) % MOD;
		I[i] = Ridic(F[i], MOD-2);
	}
}
