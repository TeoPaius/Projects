/*
	Sa se det valaoarea maxima a obiectelor de valori v[1].. v[n] 
    si greutati g[1].. g[n] care pot fi puse intr-un rucsac de capacitate G
    Rucsacul nu terbuie sa fie neaparat plin
	
*/
#include <fstream>
using namespace std;

#define MAX_S 1000
#define MAX_N 100

// se poate face optimizare in memorie
int c[MAX_N][MAX_S];        // c[i][j] val. max. obtinuta cu obiecte din intervalul [1..i] care au greutatea totala MAXIMA j
int t[MAX_N][MAX_N];        // t[i][j] = 
int n, G;
int g[MAX_N], v[MAX_N];

ofstream fout("knapsack.out");

void Load();
void Knapsack();
void Write();

int main()
{
	Load();
	Knapsack();
	Write();
	
	fout.close();
}

void Load()
{
	ifstream fin("knapsack.in");
	fin >> n >> G;
	for (int i = 1; i <= n; ++i )
		fin >> g[i] >> v[i];
	fin.close();
}

void Knapsack()
{
	// c[0][j] = 0 si c[i][0] = 0
	
	for ( int i = 1; i <= n; ++i )
		for ( int j = 0; j <= G; ++j )
		{
			c[i][j] = c[i-1][j];
			t[i][j] = t[i-1][j];
			if ( j >= g[i] & c[i][j] < c[i-1][j - g[i]] + v[i] )
			{
				c[i][j] = c[i-1][j - g[i]] + v[i];
				t[i][j] = g[i];
			}
		}
}

void Objects(int i, int s)
{
	if ( !i || !s )
		return;
	if ( t[i][s] == t[i-1][s] )
		Objects(i - 1, s);
	else
	{
		Objects(i - 1, s - t[i][s]);
		fout << g[i] << ' ';
	}
}


void Write()
{	
	fout << c[n][G] << '\n';
	Objects(n, G);
}
























