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
int c[2][MAX_S];        // c[i][j] val. max. obtinuta cu obiecte din intervalul [1..i] care au greutatea totala MAXIMA j
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
	
	int lc = 1, lp = 0;
	for ( int i = 1; i <= n; lc = !lc, lp = !lp, ++i )
		for ( int j = 0; j <= G; ++j )
		{
			c[lc][j] = c[lp][j];
			if ( j >= g[i] && c[lc][j] < c[lp][j - g[i]] + v[i] )
				c[lc][j] = c[lp][j - g[i]] + v[i];
		}
}



void Write()
{	
	fout << c[n][G] << '\n';

}
























