#include <fstream.h>
#define INFILE "taxe.in"
#define OUTFILE "taxe.out"
#define DIM 101

int n;
long S;
int a[DIM][DIM];
long b[DIM][DIM];     // matricea costurilor

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

typedef struct nod {
	int i, j;
	nod *urm;
} *PNOD, NOD;

PNOD prim;
PNOD ultim;

void Citeste();
void Rezolva();
void Add(int l, int c);


int main ()
{
	Citeste ();
	Rezolva ();

	return 0;
}


void Add(int l, int c)
{
  if (prim == NULL)  // coda vida
  {
	 prim = new NOD;
	 prim->urm = NULL;
	 prim->i = l;
	 prim->j = c;
	 ultim = prim;
  }
  else
  {
	 PNOD p;
	 p = new NOD;
	 p->urm = NULL;
	 p->i = l;
	 p->j = c;
	 ultim->urm = p;
	 ultim = p;
  }
}

void Remove ()
{
	PNOD p;
	p = prim;
	prim = prim->urm;
	delete p;
}


void Citeste ()
{
	ifstream fin(INFILE);
	fin >> S >> n;
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			fin >> a[i][j];
	fin.close();
}

void Rezolva ()
{
	Add(1, 1); // bag in coada configuratia initiala (1, 1)
	b[1][1] = a[1][1];

	PNOD p;
	p = prim;

	int inou, jnou, k;
	while (p != NULL)   // cat timp lista nu e vida
	{
		for (k = 0; k < 4; k++)
		{
			inou = p->i + di[k];
			jnou = p->j + dj[k];
			if (inou > 0 && inou <= n && jnou > 0 && jnou <= n)
				if (b[inou][jnou] == 0 || b[inou][jnou] > b[p->i][p->j] + (long)(a[inou][jnou]))
				{
					b[inou][jnou] = b[p->i][p->j] + (long)(a[inou][jnou]);
					Add(inou, jnou);
				}
		}
		p = p->urm;
		Remove ();   // sterge vechiul cap al cozii
	}

	ofstream fout(OUTFILE);
	if (	S < b[n][n]) fout << "-1";
		else fout << S - b[n][n];

	fout.close();
}
