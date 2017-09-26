/*
	Sa se gaseasca un drum de cost minim intr-o matrice, cu plecarea
	dintr-un punct dat si cu sosirea pe latura de est.
*/

#include <fstream.h>
const int DIM = 102;
const int INFINIT = 10000;
const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
typedef int MATR[DIM][DIM];
int huge c[DIM * DIM][2];

struct tata {
	int l;
	int c;
} huge t[DIM][DIM];

MATR a; // matricea data
MATR b; // matr costurilor minime
int prim, ultim; // pozitia capetelor cozii ( liniile lor )
int m, n, is, js;
void Citeste();
void Afiseaza();
int Bun(int i, int j);
void Lee();

ofstream g("matr.out");

int main()
{
	Citeste();
	Lee();
	Afiseaza();
	return 0;
}



void Citeste()
{
	ifstream f("matr.in");
	f >> m >> n >> is >> js;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			f >> a[i][j];
			b[i][j] = INFINIT;
		}
	for(i = 0; i <= m + 1; i++)
		b[i][0] = b[i][n + 1] = INFINIT;
	for(int j = 0; j <= n + 1; j++)
		b[0][j] = b[m + 1][j] = INFINIT;
	f.close();
}
int Bun(int i, int j)
{
	if ( i < 1 || i > m || j < 1 || j > n ) return 0;
	return 1;
}


void Lee()
{
	int in, jn, i, j;
	prim = ultim = 0;
	c[prim][0] = is;
	c[prim][1] = js;
	b[is][js] = a[is][js];
	while(prim <= ultim) // cat timp mai am elemente in coada
	{
		for(int dir = 0; dir < 8; dir++)
		{
			i = c[prim][0];
			j = c[prim][1];
			in = i + di[dir];
			jn = j + dj[dir];
			if (Bun(in, jn)) // daca vec nu e pe bordura
			{
				if (b[in][jn] > b[i][j] + a[in][jn]) // daca vecinul poate suferi modificare de cost
				{
					b[in][jn] = b[i][j] + a[in][jn];
					t[in][jn].l = i;
					t[in][jn].c = j;
					ultim++;                // fac loc la sf cozii
					c[ultim][0] = in;       // il pun in coada
					c[ultim][1] = jn;
				}
			}
		}
		prim++; // extrage urmat elem din coada
	}//while
}

void Afis(int i, int j)
{
	if ( t[i][j].l == 0 && t[i][j].c == 0 )
	{
		g << i << " " << j << endl;
		return;
	}
	Afis(t[i][j].l, t[i][j].c);
	g << i << " " << j << endl;
}

void Afiseaza()
{

	int l = 1;
	int min = b[1][n];
	for(int i = 1; i <= m; i++)
		if(b[i][n] < min)
			min = b[l = i][n];
	g << b[l][n] << endl;
	Afis(l, n);
}




