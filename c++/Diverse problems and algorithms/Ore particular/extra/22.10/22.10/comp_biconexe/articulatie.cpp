// Determinarea punctelor de articulatie ale unui graf neorientat
#include <fstream>
using namespace std;

const int MAX = 100;
int a[MAX][MAX];
int n, m;       // noduri, muchii
int p[MAX];     // p[i] == 1 daca i e pct. critic.
int t[MAX];     // sir de tati
int niv[MAX];   // nivelul fiecarui nod in arborele DF
int l[MAX];     // niv minim in arbore pe care se p ajung dintr-un nod sau
                // dintr-unul dintre descendentii lui
                // printr-o singura muchie de intoarcere
int root;       // nodul ales radacina
int nr;         // nr de muchii "de arbore" care "ies" din radacina  
int s[MAX];     // marcheaza nodurile vizitate

void Read();
void Write();
void DF(int nod, int nv);
void PuncteArticulatie();

int main()
{
	Read();
	root = 1;
	DF(root, 1);           // O(m)
	PuncteArticulatie();   // O(n)
	Write();               // O(n)
	return 0;
}

void Read()
{
	int x, y;
	ifstream fin("graf.in");
	fin >> n >> m;
	for (int i = 1; i <= m; i++ )
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	fin.close();
}

void DF(int nod, int nv)   // O(m)
{
	if ( nv == 2 ) nr++;
	niv[nod] = nv;
	l[nod] = nv;
	s[nod] = 1;
	for (int i = 1; i <= n; i++ )
		if ( a[nod][i] )
			if ( !s[i] )
			{
				t[i] = nod;
				DF(i, nv + 1);
				if ( l[i] < l[nod] ) l[nod] = l[i];
			}
			else
				if ( l[nod] > niv[i] && i != t[nod] ) l[nod] = niv[i];
}

void PuncteArticulatie()
{
	if ( nr > 1 ) p[root] = 1;   // rad e p de artic. 
	for (int i = 1; i <= n; i++ )
		if ( i != root )
			if ( t[i] != root && l[i] >= niv[t[i]] )
				p[t[i]] = 1;
}

void Write()
{
	ofstream fout("graf.out");
	fout << "tati:\n";
	int i;
	for ( i = 1; i <= n; i++ )
		fout << t[i] << " ";

	fout << "\nniv\n";	
	for ( i = 1; i <= n; i++ )
		fout << niv[i] << " ";
	
	fout << "\nl:\n";
	for ( i = 1; i <= n; i++ )
		fout << l[i] << " ";
	fout << "\n";

	fout << "punctele de articulatie:\n";
	for ( i = 1; i <= n; i++ )
		if ( p[i] ) fout << i << " ";
	fout.close();
}




