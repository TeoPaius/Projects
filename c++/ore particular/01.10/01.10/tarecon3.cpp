// O(m + n)
// DF()  pt retinerea nodurilor in ordinea timpilor de finish
// DFT() pe graful transpus in ordinea scaderii timpilor de finish

#include <fstream.h>
#define DIM 100

struct nod {
	int vf;
	nod* urm;
} *varf;           // adresa varfului stivei

int a[DIM][DIM], n;
int v[DIM];
int s[DIM];
int nrc;          // nr comp conexe


ofstream fout("gr.out");

void Read(char num[]);
void Afis(char num[]);
void DF(int nod);
void DFT(int nod);
void TareConexe();

int main()
{
    Read("gr.in");
	TareConexe();
	fout.close();

	return 0;
}

void Push(int val)
{
	if (!varf)
	{
		varf = new nod;
		varf->vf = val;
		varf->urm = 0;
	}
	else
	{
		nod *p = new nod;
		p->vf = val;
		p->urm = varf;
		varf = p;
	}
}

void DF(int nod)
{
	v[nod] = 1;
	for ( int i = 1; i <= n; i++ )
		if ( a[nod][i] && !v[i] ) DF( i );
	Push(nod);
}

void DFT(int nod)  // Deep First pe graful transpus
{
	s[nod] = 1;
	fout << nod << " ";
	for ( int i = 1; i <= n; i++ )
		if ( a[i][nod] && !s[i] ) DFT( i );
}

void Read(char num[])
{
	ifstream fin(num);
	fin >> n;
	int i, j;

	while ( fin >> i >> j )
		a[i][j] = 1;

	fin.close();
}

void TareConexe()
{
    int i;
    for ( i = 1; i <= n; i++ )
		if ( !v[i] ) DF(i);

    for ( nod* p = varf; p; p = p->urm )
		if ( !s[p->vf] )
		{
	     	fout << "comp nr " << ++nrc << " : ";
	     	DFT(p->vf);
	     	fout << "\n";
		}
}


