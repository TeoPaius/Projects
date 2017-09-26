//trece 6 teste din 10 ( ca timp de executie)
// testele 7 si 8 intre intre 1 si 2 secunde
// testul 9 ->  3 virgula 3 secunde

#include <fstream.h>
#include <iomanip.h>

#define FIN "urgenta.in"
#define FOUT "urgenta.out"


#define MUCHII 32390
#define NODURI 259


int  cost[MUCHII], (*u)[2], p[NODURI], rang[NODURI];
int* nr_ordine; // nr ordine al muchiilor
int* luata;
int (*graph)[2]; // backup pt graf
int nr, j, i, n;
long int cost_min, cost_total, grav_max;
long int m; // nr muchii
int K; // nr de grupuri final
int nr_grupuri;

void Citeste();
void Afiseaza();
int Find(int x);
void Union(int x, int y);
void SortMuchii(int, int);
void Kruskal();

void Union(int,int);
int Find(int);


int main()
{
	Citeste();
	Kruskal();
	Afiseaza();
	return 0;
}

void Citeste(void)
{
	ifstream fin(FIN);
	fin >> n >> m >> K;  // nr varfuri si nr muchii
	u     = new int [m + 1][2];
	graph = new int [m + 1][2];
	nr_ordine = new int [m + 1];
	luata = new int [m + 1];

	for ( i = 1; i <= m; i++  )
	{

		fin >> u[i][0] >> u[i][1] >> cost[i];
		graph[i][0] = u[i][0];
		graph[i][1] = u[i][1];
		cost_total += (long)cost[i];
		nr_ordine[i] = i;
		luata[i] = 0;
	}

	fin.close();
}

void Afiseaza()
{
	ofstream fout(FOUT);

	grav_max = cost_total - cost_min;
	fout << grav_max << endl
		 << m - nr << endl; //<<  m - nr << endl; // muchiile care nu fac parte din comp conexe

	for ( i = 1; i <= m; i++ )
		if ( !luata[i] ) fout << graph[i][0] << " " << graph[i][1] << endl;


	delete [] u;
	delete [] graph;

	delete [] luata;

	delete [] nr_ordine;
	fout.close();
}

void SortMuchii(int st, int dr)
{
	int pivot = cost[st];
	int i = st - 1, j = dr + 1;
	do
  	{
		do {  i++; } while ( cost[i] < pivot );
		do { j--; } while ( cost[j] > pivot );
		if ( i <= j )
		{
			int aux = cost[i]; cost[i] = cost[j]; cost[j] = aux;
			aux = u[i][0]; u[i][0] = u[j][0]; u[j][0] = aux;
			aux = u[i][1]; u[i][1] = u[j][1]; u[j][1] = aux;
			aux = nr_ordine[i]; nr_ordine[i] = nr_ordine[j]; nr_ordine[j] = aux;
		}
	} while ( i <= j );

	if ( st < j ) SortMuchii(st, j);
	if ( i < dr ) SortMuchii(i, dr);
}

void Union(int x, int y)
{
	if (rang[x] > rang[y]) p[y] = x;
		else
		{
			p[x] = y;
			if (rang[x] == rang[y]) ++rang[y];
		}
}

int Find(int x)      // cautare cu compresie
{
	if ( x != p[x] ) p[x] = Find(p[x]);
	return p[x];
}

void Kruskal(void)
{
	// Formeaza multimile
	for(i = 1; i <= n; i++)
	{
		p[i] = i;     // n arbori cu 1 varf
		rang[i] = 0;  // adincime 0 in arbore
	}

	SortMuchii(1, m);
	cost_min = 0;
	nr = 0;  // nr de muchii ale arborelui partial
	int nr_grupuri = n;

	for(i = 1; i <= m; i++)
	{
		if ( nr_grupuri == K ) goto end;
		int x, y;
		x= Find(u[i][0]);
		y = Find(u[i][1]);
		Union( x, y );

		if ( x != y )
		{
			luata[nr_ordine[i]] = 1;
			cost_min += (unsigned long )cost[i];
			nr++;          // am luat
			nr_grupuri--;  // au ramas
		}

	}
	end:
	return;
}
