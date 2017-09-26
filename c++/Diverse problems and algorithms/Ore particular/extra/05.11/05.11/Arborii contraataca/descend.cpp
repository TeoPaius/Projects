#include <fstream.h>
#define DIM 5001

fstream fin("asc.in", ios::in), fout("asc.out", ios::out);

typedef struct nod {
	int vf;
	nod *urm;
} NOD, *PNOD;

int n, m;
int *d, *f;
int tata[DIM];
int timp;

PNOD L[DIM];

void Read();
void DFS(int nod);
void Compute();
void Add(int i, int j);

int main()
{
	Read();     // O(n)
	DFS(1);     // O(n)
	Compute();  // O(m)
	fin.close();
	fout.close();
	return 0;
}               // Total O(m + n) = O(m)

void Read()     // O(n)
{
	int v1, v2;
	fin >> n;          // O(1)
	d = new int[n];
	f = new int[n];
	for ( int i = 1; i < n; i++ )  // O(n)
	{
		fin >> v1 >> v2;
		Add(v1, v2);     // O(1)
		Add(v2, v1);
	}
}

void Add(int i, int j)
{
	PNOD p = new NOD;
	p->vf = i;
	p->urm = L[j];
	L[j] = p;
}

void DFS(int nod)
{
	PNOD p = L[nod];
	d[nod] = ++timp;
	while (p)
	{
		if (tata[nod] != p->vf)
		{
			tata[p->vf] = nod;
			DFS(p->vf);
		}
		p = p->urm;
	}
	f[nod] = ++timp;
}
/*
void DFS(int nod)
{
	d[nod] = ++timp;
	for (PNOD p = L[nod]; p; p = p->urm )
		if (tata[nod] != p->vf)
		{
			tata[p->vf] = nod;
			DFS(p->vf);
		}

	f[nod] = ++timp;
}
*/
void Compute()   // O(m)
{
	int v1, v2;
	fin >> m; // nr de intrebari(query)
	for ( int i = 1; i <= m; i++ )
	{
		fin >> v1 >> v2;
		if ( d[v1] < d[v2] && f[v2] < f[v1] )
			fout << "DA  ASCENDENT" << endl;    // O(1)
		if ( d[v2] < d[v1] && f[v1] < f[v2] )
			fout << "DA  DESCENDENT" << endl;
		if ( f[v1] < d[v2] || f[v2] < d[v1] )
			fout << "NU" << endl;
	}
}
