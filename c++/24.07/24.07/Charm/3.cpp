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

vector<int> g, v, c1, c2;
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
	c1.resize(M + 1); c2.resize(M + 1);
	for ( int i = 1; i <= n; ++i )
		fin >> g[i] >> v[i];
	
	fin.close();
}

void Knapsack()
{
	for ( int i = 1; i <= n; ++i )
	{
		for ( int j = 0; j <= M; ++j )
		{
			c2[j] = c1[j];
			if ( j >= g[i] && c2[j] < c1[j-g[i]] + v[i] )
				c2[j] = c1[j-g[i]] + v[i];
		}
		c1 = c2; 
	}
}

void Write()
{
	ofstream fout("charm.out");
	fout << c2[M] <<'\n';
	fout.close();
}

				
