/// Charm - USACO
// teste OK dar TLE-uri
#include <fstream>
#include <vector>
using namespace std;

#define MAX_S 12880
#define MAX_N 4302


void Read();
void Write();
void Knapsack();


vector<int> g, v, c[2];
int n, M;

int main()
{
	Read();
	Knapsack();
	Write();
	
	return 0;
}

void Read()
{
	ifstream fin("charm.in");
	fin >> n >> M;
	g.resize(n + 1);  v.resize(n + 1);
	c[0].resize(M + 1); c[1].resize(M + 1);
	for ( int i = 1; i <= n; ++i )
		fin >> g[i] >> v[i];
	
	fin.close();
}

int i, lc, lp;

void Knapsack()
{
	for ( i = 1, lc = 1, lp = 0; i <= n; lc = !lc, lp = !lp, ++i )
	{
		for ( int j = 0; j <= M; ++j )
		{
			c[lc][j] = c[lp][j];
			if ( j >= g[i] && c[lc][j] < c[lp][j-g[i]] + v[i] )
				c[lc][j] = c[lp][j-g[i]] + v[i];
		}
	}
}

void Write()
{
	ofstream fout("charm.out");
	fout << c[lp][M] <<'\n';
	fout.close();
}

				
