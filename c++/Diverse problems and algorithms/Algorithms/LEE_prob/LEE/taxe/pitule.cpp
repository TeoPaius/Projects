
#include <fstream.h>
#include <iomanip.h>
#include <values.h>
const int DIM = 500;
#define INFINIT  2000000;
const int di[] = {-1, 0, 1, 0};
const int dj[] = { 0, 1, 0, -1};


unsigned long int  c[DIM* DIM][2];

int  a[DIM][DIM];
unsigned long int   b[DIM][DIM]; // matricea data; // matr costurilor minime
int prim, ultim; // pozitia capetelor cozii ( liniile lor )
int n;
int S; // Suma de bani initiala
void Citeste();
void Afiseaza();
int Bun(int i, int j);
void Lee();

ofstream g("taxe.out");

int main()
{
	Citeste();
	Lee();
	Afiseaza();
	return 0;
}




void Citeste()
{
	ifstream f("taxe.in");
	f >> S >> n;
   int i;
	for(i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			f >> a[i][j];
			b[i][j] = INFINIT;
		}

	f.close();
}
int Bun(int i, int j)
{
	if ( i < 1 || i > n || j < 1 || j > n ) return 0;
	return 1;
}


void Lee()
{
	int in, jn, i, j;
	prim = ultim = 0;
	c[prim][0] = 1;
	c[prim][1] = 1;
	b[1][1] = a[1][1];

	while(prim <= ultim) // cat timp mai am elemente in coada
	{
		i = c[prim][0];
		j = c[prim][1];

		for(int dir = 0; dir < 4; dir++)
		{
			in = i + di[dir];
			jn = j + dj[dir];
			if (Bun(in, jn)) // daca vec nu e pe bordura
			{
				if (b[in][jn] > b[i][j] + a[in][jn]) // daca vecinul poate suferi modificare de cost
				{
					b[in][jn] = b[i][j] + a[in][jn];
					ultim++;                // fac loc la sf cozii
					c[ultim][0] = in;       // il pun in coada
					c[ultim][1] = jn;
				}
			}
		}
		prim++; // extrage urmat elem din coada
	}//while

}


void Afiseaza()
{
	int i, j;
/*
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++)
			g << b[i][j] << " ";
		g << endl;
	}
	g << endl << endl;
*/

	if ( S >= b[n][n] ) g << S - b[n][n];
		else g << -1;
	g.close();
}




