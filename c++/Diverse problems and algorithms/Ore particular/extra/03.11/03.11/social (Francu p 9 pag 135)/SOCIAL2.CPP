// P9 pag 135 Catalin Francu
#include <conio.h>
#include <fstream.h>
#define MAX 100

typedef struct nod {
	int vf;
	nod* urm;
} NOD, *PNOD;

PNOD L[MAX];
typedef int SIR[MAX];

SIR P, Q;
int n, tata;    // nr noduri
int root, fiu; // rad

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
	for ( i = 1; i <= n; i++ )
	{
		fin >> tata;
		if ( tata == 0 ) root = i;
		Add(tata, i); // ca graf orientat
	}

	for ( i = 1; i <= n; i++ )
	{
		fin >> P[i];
	}
	fin.close();
}


// PD in model Bottom-Up
void DF(int nod)
{
	int fiu;
	for (PNOD p = L[nod]; p; p = p->urm )
	{
		fiu = p->vf;
		DF(fiu); // nu pot urca spre tata
		P[nod] += Q[fiu];
		Q[nod] += Max(P[fiu], Q[fiu]);
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
/*
	fout << "P ";
	for ( int i = 1; i <= n; i++ )
		fout << P[i] << " ";

	fout << endl;
	fout << "Q ";
	for ( i = 1; i <= n; i++ )
		fout << Q[i] << " ";
	fout << endl;
*/
	fout << P[root] << "\n";
	fout.close();
}


int Max(int a, int b)
{
	if (a >= b ) return a;
	return b;
}