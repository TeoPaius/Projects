/// Charm - USACO
#include <fstream>
using namespace std;

#define MAX_S 12880
#define MAX_N 4302


void Read();
void Write();
void Knapsack();

int n, M, c[MAX_N][MAX_S], g[MAX_N], v[MAX_N];

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
	for ( int i = 1; i <= n; ++i )
		fin >> g[i] >> v[i];
	
	fin.close();
}

void Knapsack()
{
	for ( int i = 1; i <= n; ++i )
		for ( int j = 0; j <= M; ++j )
		{
			c[i][j] = c[i-1][j];
			if ( j >= g[i] && c[i][j] < c[i-1][j-g[i]] + v[i] )
				c[i][j] = c[i-1][j-g[i]] + v[i];
		}
}

void Write()
{
	ofstream fout("charm.out");
	fout << c[n][M] <<'\n';
	fout.close();
}

				