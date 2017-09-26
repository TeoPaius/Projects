// P9 pag 135 Catalin Francu
#include <conio.h>
#include <fstream.h>

typedef struct nod {
	int vf;
	nod* urm;
} NOD, *PNOD;

PNOD* L;

int n;    // nr noduri
int root; // rad
int *P;   // P[i] socoabilit max pt subarb cu rad in i, daca i participa la petecere
int *Q;   // Q[i] socoabilit max pt subarb cu rad in i, daca i NU participa la petecere
int tata;

void Add(int i, int j);
void Read();
void Write();
int Max(int a, int b);
void DF(int nod);

int main()
{
	Read();
	DF(root);
	Write();
	return 0;
}

void Read()
{
	ifstream fin("soc.in");
	int i, v1, v2;

	fin >> n;
	P = new int [n + 1];
	Q = new int [n + 1];
	L = new PNOD [n + 1];  // nod*

	memset(P, 0, sizeof(int)*(n+1));  // memset(P, 0, sizeof(P));
	memset(Q, 0, sizeof(int)*(n+1));
	memset(L, 0, sizeof(PNOD)*(n+1));


	for ( i = 1; i <= n; i++ )
	{
		fin >> tata;
		if ( tata == 0 ) root = i;
		Add(tata, i); // ca graf orientat
	}

	for ( i = 1; i <= n; i++ )
	{
		fin >> P[i];    // se initializeaza P[] cu socibilitatea angajatilor
	}
	fin.close();
}

void DF(int nod)
{
	for (PNOD p = L[nod]; p; p = p->urm )
	{
		DF(p->vf); // nu pot urca spre tata (nu am arc spre el)
		P[nod] += Q[p->vf];
		Q[nod] += Max(P[p->vf], Q[p->vf]);
	}
}

void Add(int i, int j)
{
	PNOD p = new NOD;
	p->vf = j;
	p->urm = L[i];
	L[i] = p;
}

void Write()
{
	ofstream fout("soc.out");
	fout << P[root] << "\n";
	fout << "P ";
	for ( int i = 1; i <= n; i++ )
		fout << P[i] << " ";

	fout << '\n';
	fout << "Q ";
	for ( int i = 1; i <= n; i++ )
		fout << Q[i] << " ";
	fout << '\n';

	fout.close();
}


int Max(int a, int b)
{
	if (a >= b ) return a;
	return b;
}