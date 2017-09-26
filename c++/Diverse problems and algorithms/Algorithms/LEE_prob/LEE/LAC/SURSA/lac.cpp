
#include <stdio.h>

int a[102][102]; // matricea care descrie lacul
int b[102][102]; // matricea care contine costul ajungerii in fiecare punct
int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct tata {
	int i;
	int j;
} huge t[102][102];

int m, n; // dimensiunile lacului
FILE *f;  // fisierul de iesire

void CitesteDate(void)
{
	FILE *f = fopen("t9", "rt");
	fscanf(f,"%d%d", &m, &n);
	for ( int  i = 1; i <= m; i++)
	for ( int j = 1; j <= n; j++)
	{
		fscanf(f,"%d",&a[i][j]);
		t[i][j].i = t[i][j].j = 0;
	}
	fclose(f);
}

int minVecini(int i, int j, int& inou, int& jnou)
{
	int min = b[i][j];
	int in, jn;
	for ( int dir = 0; dir < 8; dir++ )
	{
		in = i + di[dir];
		jn = j + dj[dir];

		if ( b[in][jn] < min)
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
	// initializarea matricei de costuri
	// 0 in afara matricei (inainte de prima linie), "infinit" in rest;
	// pentru "infinit" se alege valoarea m+1 deoarece cu siguranta se va obtine ca solutie o valoare mai mica decat m
	int imbunatatiri; // arata daca parcurgerea a adus imbunatatiri
	int x, y; // indica directia din care se ajunge in pozitia curenta
	for ( int i = 1; i <= m + 1; i++ ) // numai linia 0 este 0
		for ( int j = 0; j <= n + 1; j++ )
			b[i][j] = m + 1;
	do
	{
		// se realizeaza parcurgeri pana nu mai apar imbunatatiri (actualizari de costuri)
		imbunatatiri = 0;
		for ( int i = 1; i <= m; i++ )
			for ( int j = 1; j <= n; j++ )
			{
				int min = minVecini(i, j, x, y); //X, Y - COORDONATELE VECINULUI CU COST MINIM
				if ( b[i][j] > min + a[i][j] )
				{ //daca se p ajunge in (i,j) prin (x, y) cu un cost mai mic decat cel actual
					b[i][j] = min + a[i][j];
					t[i][j].i = x;
					t[i][j].j = y;
					imbunatatiri = 1;
				}
	}
  }	while ( imbunatatiri );
}

void AfiseazaSolutia(int i, int j )
{
	if ( t[i][j].i == 0 && t[i][j].j == 0 ) return;
	AfiseazaSolutia(t[i][j].i, t[i][j].j);
	if ( a[i][j] )
		fprintf(f, "%d %d\n", i, j);
}

void ScrieSolutia(void)
{
	// determinarea minimului de pe ultima linie si a pozitiei acestuia
	f = fopen("LAC.OUT","wt");
	int min = b[m][1];
	int ind = 1;
	for (int i = 2; i <= n; i++)
	if ( b[m][i] < min )
		min = b[m][ind = i];

	fprintf(f,"%d\n",min);
	AfiseazaSolutia(m, ind); // se afiseaza pozitiile in care au fost amplasate pontoane parcurgand drumul in sens invers
	fclose(f);
}

int main()
{
	CitesteDate();
	DeterminaSolutia();
	ScrieSolutia();
}