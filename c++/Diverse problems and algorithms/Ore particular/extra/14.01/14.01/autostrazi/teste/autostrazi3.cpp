#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define MOD 30011
using namespace std;

ifstream is("0-autostrazi.in");
ofstream os("autostrazi.out");
//typedef vector<int> VI;
using VI = vector<int>;

int n, s, m;
VI r;
vector<VI> g;
bitset<101> ok;

void Read();
VI Solve(int nod);

int main()
{
	Read();
	VI a = Solve(1);
	int answ;
	for ( const auto& i : a )
	{
		answ += i;
		if ( answ >= MOD )
			answ -= MOD;
	}
	cout << answ;
	is.close();
	os.close();
	return 0;
}

VI Solve(int nod)
{
	VI c(s + 1);
	c[0] = 1;
	ok[nod] = true;
	for ( const auto& nodv : g[nod] )
	{
		if ( ok[nodv] )
			continue;
		VI cv = Solve(nodv);
		VI aux(s + 1);
		for ( int i = 0; i <= m; ++i )
			for ( int j = 0; j + r[i] <= s; ++j )
				for ( int k = 0; j + r[i] + k <= s; ++k )
				{
					aux[max(j, r[i] + k)] += ( c[j] * cv[k] ) % MOD;
					if ( aux[max(j, r[i] + k)] >= MOD )
						aux[max(j, r[i] + k)] -= MOD;
				}
		c = aux;
	}
	return c;
}

void Read()
{
	cin >> n >> s >> m;
	r = VI(m + 1);
	for ( int i = 1; i <= m; ++i )
		cin >> r[i];
	g = vector<VI>(n + 1);
	int n1, n2;
	for ( int i = 1; i < n; ++i )
	{
		cin >> n1 >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}
}
