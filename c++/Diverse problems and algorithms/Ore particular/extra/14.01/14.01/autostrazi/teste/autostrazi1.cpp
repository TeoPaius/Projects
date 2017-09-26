#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define MOD 30011
using namespace std;

ifstream is("0-autostrazi.in");
ofstream os("autostrazi.out");

int n, s, m;
vector<vector<int>> c;
vector<int> r, aux;
vector<vector<int>> g;
bitset<101> ok;

void Read();
void Solve(int nod);

int main()
{
	Read();
	Solve(1);
	int answ;
	for ( const auto& i : c[1] )
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

void Solve(int nod)
{
	c[nod][0] = 1;

	ok[nod] = true;
	for ( const auto& nodv : g[nod] )
	{
		if ( ok[nodv] )
			continue;
		Solve(nodv);
		
		aux.assign(s + 1, 0);
		for ( int i = 0; i <= m; ++i )
			for ( int j = 0; j + r[i] <= s; ++j )
				for ( int k = 0; j + r[i] + k <= s; ++k )
				{
					aux[max(j, r[i] + k)] += ( c[nod][j] * c[nodv][k] ) % MOD;
					if ( aux[max(j, r[i] + k)] >= MOD )
						aux[max(j, r[i] + k)] -= MOD;
				}
		c[nod] = aux;
	}
}

void Read()
{
	cin >> n >> s >> m;
	r.resize(m + 1);
	c = vector<vector<int>> (n + 1, vector<int> (s + 1) );
	aux.resize(s + 1);
	for ( int i = 1; i <= m; ++i )
		cin >> r[i];
	g.resize(n + 1);
	int n1, n2;
	for ( int i = 1; i < n; ++i )
	{
		cin >> n1 >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}
}
