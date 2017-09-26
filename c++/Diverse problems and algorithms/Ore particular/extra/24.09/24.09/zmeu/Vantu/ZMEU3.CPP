#include <fstream.h>
#define MAX 100
#define INFINIT 30000
#define IN "zmeu.in"
#define OUT "zmeu.out"

typedef struct Nod{
	char i, j, timp, capr;
	Nod* urm;
} NOD, *PNOD;

struct Poveste{
	int t, c;
} s[MAX];

PNOD prim, ultim;
int n, p, k;
char a[MAX][MAX];
int tmin[MAX][MAX];


void Citeste();
void Latime();
int Bun( PNOD p1, int i );
void Afiseaza();
void Adauga( int i, int j, int timp, int capr );
void Sterge();

int main()
{
	Citeste();
	Latime();
	Afiseaza();

	return 0;
}

void Citeste()
{
	ifstream f( IN );
	f >> n >> p >> k;
	int i, j, aux1, aux2;
	for ( i = 1; i <= p; i++)
		f >> s[i].t >> s[i].c;
	for ( i = 1; i < p; i++)
		for ( j = 2; j <= p; j++)
		{
			if ( i != j ) a[i][j] = 1;
			tmin[i][j] = INFINIT;
	   }
	for ( i = 1; i <= k; i++)
	{
		f >> aux1 >> aux2;
		a[aux1][aux2] = 0;
	}
	a[1][p] = 0;
	f.close();
}

void Latime()
{
	Adauga( 0, 1, 0, n - s[1].c);
	tmin[0][1] = s[1].t;
	PNOD p1 = prim;
	int i;

	while( p1 != NULL )
	{
		for ( i = 1; i <= p; i++)
		{
			if ( Bun( p1, i) )
			{
				Adauga( p1->j, i, s[i].t + p1->timp, p1->capr - s[i].c );
				tmin[p1->j][i] = tmin[p1->i][p1->j] + s[i].t;
			}

		}
		p1 = p1->urm;
		Sterge();
	}
}

int Bun( PNOD p1, int i)
{
	if ( a[p1->j][i] == 0 || p1->j == i ) return 0;
	if ( p1->capr - s[i].c < 1  ) return 0;
	if ( tmin[p1->j][i] < tmin[p1->i][p1->j] + s[i].t ) return 0;
	return 1;
}

void Afiseaza()
{
	ofstream fout( OUT );

	int i, min = INFINIT;
	for ( i = 1; i <= p; i++)
		if ( tmin[i][p] != 0 && tmin[i][p] < min ) min = tmin[i][p];

	if ( min != INFINIT )	fout << min;
	else fout << -1;
	fout.close();
}

void Adauga(int i, int j, int timp, int capr)
{
  if (prim == NULL)
  {
	 prim = new NOD;
	 prim->urm = NULL;
	 prim->i = i;
	 prim->j = j;
	 prim->timp = timp;
	 prim->capr = capr;
	 ultim = prim;
  }
  else
  {
	 PNOD p;
	 p = new NOD;
	 p->urm = NULL;
	 p->i = i;
	 p->j = j;
	 p->timp = timp;
	 p->capr = capr;
	 ultim->urm = p;
	 ultim = p;
  }
}

void Sterge()
{
	PNOD p1;
	p1 = prim;
	prim = prim->urm;
	delete p1;
}