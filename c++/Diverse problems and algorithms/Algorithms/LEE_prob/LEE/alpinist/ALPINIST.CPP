#include <stdio.h>
#define ALTIT_MAX 1001
#define COST_MAX 1500


int a[10][10]; // matricea care descrie muntele
int b[10][10]; // matricea care contine costul ajungerii in fiecare punct
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
int hmax; //inalt max posibil de atins pornind pornind dintr-un punct de altit 0
int imax, jmax; // coord acelui punct

struct tata {
	int i;
	int j;
}  t[102][102];

int m, n; // dimensiunile muntelui
FILE *f;  // fisierul de iesire

void CitesteDate(void)
{
	FILE *f = fopen("alpinist.in", "rt");
	int i, j;
	fscanf(f,"%d%d", &m, &n);
	for ( i = 0; i <= m + 1; i++ )
		for ( j = 0; j <= n + 1; j++ )
			b[i][j] = COST_MAX;


	for ( i = 1; i <= m; i++)
		for ( j = 1; j <= n; j++)
		{
			fscanf(f,"%d", &a[i][j]);
			if ( a[i][j] == 0 ) b[i][j] = 0;
		}
	fclose(f);
}

int MinVecini(int i, int j, int& inou, int& jnou)
{ // lung drumului minim de la un 0 (pornire) pana la cel m apropiat vecin
	int min = b[i][j];
	int in, jn;
	for ( int dir = 0; dir < 4; dir++ )
	{
		in = i + di[dir];
		jn = j + dj[dir];

		if ( b[in][jn] < min && a[i][j] - a[in][jn] <= 100)
		{
			min = b[in][jn];
			inou = in;
			jnou = jn;
		}
	}
	return min;

}

void DeterminaSolutia(void)
{
	int modificari;
	int x, y;
	do
	{
		modificari = 0;
		for ( int i = 1; i <= m; i++ )
			for ( int j = 1; j <= n; j++ )
			{
				int min = MinVecini(i, j, x, y); //x, y - COORDONATELE VECINULUI CU COST MINIM
				if ( b[i][j] > min + 1 && a[i][j] - a[x][y] <= 100 )
				{ //daca se p ajunge in (i,j) prin (x, y) cu un cost mai mic decat cel actual
					b[i][j] = min + 1;
					t[i][j].i = x;
					t[i][j].j = y;
					if ( a[i][j] > hmax )
					{
						hmax = a[i][j];
						imax = i;
						jmax = j;
					}
					modificari = 1;
				}
			}
  }	while ( modificari );
}

void AfiseazaSolutia(int i, int j )
{
	if ( t[i][j].i == 0 && t[i][j].j == 0 ) return;
	AfiseazaSolutia(t[i][j].i, t[i][j].j);
	if ( i == t[i][j].i + 1 )  fprintf(f, "S ");
	if ( i == t[i][j].i - 1 )  fprintf(f, "N ");
	if ( j == t[i][j].j + 1 )  fprintf(f, "E ");
	if ( j == t[i][j].j - 1 )  fprintf(f, "W ");
}

void AfisDrum(int i, int j)
{
	if (t[i][j].i == 0 && t[i][j].j == 0)
	{
		fprintf(f, "%d %d ", i, j);
		return;
	}
	AfisDrum(t[i][j].i, t[i][j].j);

}

void ScrieSolutia(void)
{
	// determinarea minimului de pe ultima linie si a pozitiei acestuia
	f = fopen("alpinist.out","wt");

	fprintf(f, "%d\n", hmax);
	AfisDrum(imax, jmax);
	fprintf(f, "%d %d\n", imax, jmax);
//	fprintf(f,"%d\n", b[imax][jmax]);
	AfiseazaSolutia(imax, jmax);
	fclose(f);
}

//functie de control
void Afis()
{
	FILE* g = fopen("ab.out", "wt");
	int i, j;
	for ( i = 1; i <= m; i++)
	{
		for ( j = 1; j <= n; j++ )
			fprintf(g, "%6d", a[i][j]);
		fprintf(g, "\n");
	}
	fprintf(g, "\n");
	for ( i = 1; i <= m; i++)
	{
		for ( j = 1; j <= n; j++ )
			fprintf(g, "%6d", b[i][j]);
		fprintf(g, "\n");
	}

	fprintf(g, "\n");
	for ( i = 1; i <= m; i++)
	{
		for ( j = 1; j <= n; j++ )
			fprintf(g, "   (%d, %d)", t[i][j].i, t[i][j].j);
		fprintf(g, "\n");
	}

	fprintf(g, "\n");
	fprintf(g, "%d %d \n", imax, jmax);

	fclose(g);
}

int main()
{
	CitesteDate();
	DeterminaSolutia();
//	Afis();
	ScrieSolutia();
}
