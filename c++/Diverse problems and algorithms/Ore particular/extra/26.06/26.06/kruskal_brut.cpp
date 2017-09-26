// Algoritmul lui Kruskal
// Det arborelui partial de cost minim intr-un graf
// Minimum spanning tree (arborele minim de acoperire)

#include <fstream>
using namespace std;

#define MAX 100

struct muchie {
	int v1, v2;
	int cost;
};

muchie g[MAX];     // memoreaza graful ca un sir de muchiii
int cost_min;      // costul APM - MST (arb part de cost min)
muchie arb[MAX];   // APM
int comp[MAX];     // sir carcatreistic
				   // comp[i] = j  nodul i se afla in comp conexa j)
int n, m;          // nr noduri nr muchii ale grafului

void Citeste();
void Kruskal();
void Afiseaza();

int main()
{
	Citeste();
	Kruskal();
	Afiseaza();

	return 0;
}

void Citeste()
{
	ifstream fin("kruskal.in");
	fin >> n;
	m = 0;
	int v1, v2, cost;
	while ( fin >> v1 >> v2 >> cost )
	{
		m++;
		g[m].v1    = v1;
		g[m].v2    = v2;
		g[m].cost  = cost;
	}
	fin.close();
}


void Sorteaza()
{
	for ( int i = 1; i < m; i++ )
		for ( int j = i + 1; j <= m; j++ )
			if ( g[j].cost < g[i].cost )
			{
				muchie aux = g[i];
				g[i] = g[j];
				g[j] = aux;
			}
}

void Kruskal()
{
	Sorteaza();
	int i, j;
	int k = 0;  // nr muchii in APM
	int c1, c2; // componnetele conexe ale varfurilor muchiei
	for ( i = 1; i <= n; i++ )
		comp[i] = i;

	for ( i = 1; i <= m; i++ )
		if ( comp[g[i].v1] != comp[g[i].v2] )  // daca nu formeaza ciclu
		{
			cost_min += g[i].cost;
			arb[++k] = g[i];  // adaug muchia i in APM
			c1 = comp[g[i].v1]; // Find O(1)
			c2 = comp[g[i].v2];
			for ( j = 1; j <= n; j++ ) // Union - O(n)
				if ( comp[j] == c2 ) comp[j] = c1;
			if ( k == n - 1 )  break;
		}
}

void Afiseaza()
{
	ofstream fout("kruskal.out");
	fout << "costul APM este " << cost_min << endl;
	for(int i=1; i<=n-1; i++)
		fout << arb[i].v1 << " " << arb[i].v2 << " " << arb[i].cost << endl;
	fout.close();
}



