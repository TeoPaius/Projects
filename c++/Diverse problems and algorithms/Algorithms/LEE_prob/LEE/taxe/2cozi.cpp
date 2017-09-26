#include <iostream.h>
#include <fstream.h>
#include <mem.h>
#define infinit 2000000000

fstream fin ( "taxe.in", ios::in ), fout ( "taxe.out", ios::out );
int n, a[101][101], sf, in;
long int c[101][101], s;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int huge coada1[10001][2];
int huge coada2[10001][2];

void Citeste();
void Solutie();
void Afiseaza();

int main()
{
	Citeste();
	Solutie();
	Afiseaza();
	fin.close();
	fout.close();
	return 0;
}

void Citeste()
{
	int i, j;
	sf = 1;
	fin >> s >> n;
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= n; j++ )
		{
			fin >> a[i][j];
			c[i][j] = infinit;
		}
	coada1[sf][0] = 1;
	coada1[sf][1] = 1;
	c[1][1] = a[1][1];
}

void Solutie()
{
	int i, xn, yn, min, p;
	in = 0;
	while ( sf )
	{
		for ( i = 1; i <= sf; i++ )
				for ( p = 0; p < 4; p++ )
				{
					xn = coada1[i][0] + di[p];
					yn = coada1[i][1] + dj[p];
					if ( xn >= 1 && yn >= 1 && xn <= n && yn <= n && c[coada1[i][0]][coada1[i][1]] + a[xn][yn] < c[xn][yn] )
					{
						c[xn][yn] = a[xn][yn] + c[coada1[i][0]][coada1[i][1]];
						coada2[++in][0] = xn;
						coada2[in][1] = yn;
					}
				}
		memcpy(coada1, coada2, sizeof(coada2) );
		sf = in;
		in = 0;
	}
}

void Afiseaza()
{
	int i, j;
	if ( s >= c[n][n] )fout << s - c[n][n];
	else               fout << -1;
}

