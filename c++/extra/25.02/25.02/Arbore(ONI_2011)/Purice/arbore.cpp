#include <algorithm>
#include <stdio.h>
#include <vector>

#define MAX 100010
#define restRez 666013
#define ll long long
#define pb push_back

using namespace std;

int n;
ll sol[MAX], fact[MAX], inv[MAX];
int sel[MAX], subArb[MAX];
vector <int> vctDrum[MAX], vctDrumI[MAX];

inline ll put(ll x, int p)
{
	ll r = 1;

	for (; p > 1; p /= 2)
	{
		if (p & 1)
			r = (r * x) % restRez;
		x = (x * x) % restRez;
	}

	return (x * r) % restRez;
}

inline ll combinari(int n, int k)
{
	return (((fact[n] * inv[k]) % restRez) * inv[n - k]) % restRez;
}

inline void dfs(int nod)
{
	sel[nod] = 1;
	subArb[nod] = 1;

	for (int i = 0; i < vctDrumI[nod].size(); i++)
	{
		int v = vctDrumI[nod][i];
		if (!sel[v])
		{
			dfs(v);

			vctDrum[nod].pb(v);

			subArb[nod] += subArb[v];
		}
	}
}

inline void calc(int nod)
{
	sol[nod] = 1;

	int nr = subArb[nod] - 1;
	for (int i = 0; i < vctDrum[nod].size(); i++)
	{
		int v = vctDrum[nod][i];
		calc(v);

		sol[nod] = (((sol[nod] * sol[v]) % restRez) * combinari(nr, subArb[v])) % restRez;
		nr -= subArb[v];
	}
}

int main()
{
	freopen("arbore.in", "r", stdin);
	freopen("arbore.out", "w", stdout);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		vctDrumI[n1].pb(n2);
		vctDrumI[n2].pb(n1);
	}

	dfs(1);

	fact[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % restRez;

		inv[i] = put(fact[i], restRez - 2);
	}

	calc(1);

	printf("%lld\n", sol[1]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
