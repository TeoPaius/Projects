// Determinarea muchiilor critice ale unui graf neorientat
// O( m + n )

// Muchiile de intoarcere inchid un ciclu deci nu pot fi critice
// Doar muchiile de arbore pot fi critice

#include <fstream>
using namespace std;

const int MAX = 100;
int a[MAX][MAX];
int n, m;       // noduri, muchii
//int p[MAX];   // p[i] == 1 daca i e pct. artic.
int t[MAX];     // sir de tati
int niv[MAX];   // nivelul fiecarui nod in arborele DF
int l[MAX];     // niv minim in arbore pe care se p ajung dintr-un nod sau
                // dintr-unul dintre descendentii lui
                // printr-o singura muchie de intoarcere
int root;       // nodul ales radacina
int nr;         // nr de muchii "de arbore" care "ies" din radacina
int s[MAX];     // marcheaza nodurile vizitate

ofstream fout("graf.out");

void Read();
void Write();
void DF(int nod, int nv);
void MuchiiCritice();

int main()
{
	Read();
	root = 2;
	DF(root, 1);           // O(m)
	Write();               // O(n)  DEBUG
	MuchiiCritice();       // O(n)

	fout.close();
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
	niv[nod] = nv;
	l[nod] = nv;
	s[nod] = 1;
	for (int i = 1; i <= n; i++ )
		if ( a[nod][i] )
			if ( !s[i] ) // muchie de arbore
			{
				t[i] = nod;
				DF(i, nv + 1);
				if ( l[i] < l[nod] ) l[nod] = l[i];
			}
			else        // muchie de intoarcere
				if ( l[nod] > niv[i] && i != t[nod] ) l[nod] = niv[i];
}

void MuchiiCritice()
{
	for (int i = 1; i <= n; i++ )
		if ( i != root )
			if ( l[i] > niv[t[i]] ) // era >=
				fout << t[i] << " " << i << "\n";
}

void Write()
{
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

}




