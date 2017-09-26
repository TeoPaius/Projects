// Dijkstra
#include <fstream.h>

#define FIN "zmeu.in"
#define FOUT "zmeu.out"
#define INFINIT 32000
#define M 194

#if !defined __BORLANDC__
#define huge
#endif

struct Poveste{
	int d, c;
} s[M];

int n, p, k, rez;
int huge a[M][M];
int v[M], d[M], cr[M];

void Citeste();
void Afiseaza();
void Dijkstra();

int main()
{
	Citeste();
	Dijkstra();
	Afiseaza();

	return 0;
}

void Citeste()
{
	int i, j, aux1, aux2;
	ifstream f(FIN);
	f >> n >> p >> k;      // nr initial de capete, povestile, nr arce interzise
	for ( i = 1; i <= p; i++)
		f >> s[i].d >> s[i].c; // timpul si nr capete consumate in fiecare poveste

	for ( i = 1; i <= k; i++)
	{
		f >> aux1 >> aux2;
		a[aux1][aux2] = INFINIT;
	}

	a[1][p] = INFINIT;
	v[1] = v[p] = 1;

	for ( j = 1; j <= p; j++)
	{
		if ( a[1][j] != INFINIT ) a[1][j] = s[1].d + s[j].d; // durata pov 1 + pov j
		a[j][1] = INFINIT;
		a[p][j] = INFINIT;
		a[j][j] = s[j].d;
		d[j] = a[1][j];
		if ( j != 1 ) cr[j] = n - (s[1].c + s[j].c); // capete ramase dupa pov j
			else      cr[1] = n - s[1].c;
	}

	for ( i = 1; i <= p; i++)
		for ( j = 1; j <= p; j++)
			if ( a[i][j] == 0 )
				a[i][j] = s[j].d;

}

void Dijkstra()
{
	int i, j, min, poz;
	for ( i = 1; i <= p - 2; i++)
	{
		min = INFINIT;
		poz = INFINIT;
		for ( j = 1; j <= p; j++)
			if ( v[j] == 0 && d[j] < min && (cr[j] -  s[p].c) >= 1 )
			{
				min = d[j];
				poz = j;
			}

		v[poz] = 1;
		if ( poz != INFINIT )
			for ( j = 1; j <= p; j++)
				if ( ( a[poz][j] != INFINIT && cr[poz] - s[j].c ) >= 1)
					if ( d[j] == INFINIT || d[j] > d[poz] + a[poz][j] )
					{
						d[j] = d[poz] + a[poz][j];
						cr[j] -= s[j].c;
						if ( j == p ) rez = d[j];
					}
	}
}

void Afiseaza()
{
	ofstream g(FOUT);
	if ( rez != 0 ) g << rez;
	else g << -1;
	g.close();
}

