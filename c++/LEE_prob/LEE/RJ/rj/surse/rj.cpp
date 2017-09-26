#include <fstream>
#include <iomanip>
using namespace std;


const int DIM = 101;

int m, n;
int modificare, pas;
const int  INFINITY = 10000;
char a[DIM][DIM];
int R[DIM][DIM];
int J[DIM][DIM];
int iR, jR, iJ, jJ;
int iv, jv;
const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void Lee(int c[][DIM], int is, int js);
void Read();
void Write();
int OK(int c[][DIM]);

int main()
{
	Read();
	Lee(R, iR, jR);
	Lee(J, iJ, jJ);
	Write();

	return 0;
}

void Read()
{
	ifstream fin("rj.in");
	fin >> m >> n;
	fin.get();
	for ( int i = 1; i <= m; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			a[i][j] = fin.get();
			if ( a[i][j] == 'R' ) iR = i, jR = j;
			if ( a[i][j] == 'J' ) iJ = i, jJ = j;
		}
		fin.get();   // citeste Enter
	}
/*
	for (int i = 0; i < m; i++ )
		fin.getline(a[i], 102);
*/
	fin.close();
}

int OK(int c[][DIM])
{
	if ( iv < 1 || iv > m || jv < 1 || jv > n ) return 0;  // in afara matricii
	if ( c[iv][jv] < INFINITY )return 0; // am mai calcat 
	if ( a[iv][jv] == 'X' ) return 0;    // obstacol 
	return 1;
}


void Lee(int c[][DIM], int is, int js)
{
	int i = 0, j = 0;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			c[i][j] = INFINITY;
	c[is][js] = 0;
	pas = 0;
	do
	{
		modificare = 0;
		for ( i = 1; i <= m; i++ )
			for ( j = 1; j <= n; j++ )
				if (c[i][j] == pas)
					for ( int dir = 0; dir < 8; dir++ )
					{
						iv = i + di[dir];
						jv = j + dj[dir];
						if ( OK(c) ) 
						{
							c[iv][jv] = pas + 1;
							modificare = 1;
						}	
					}
		pas++;
	} while ( modificare );
}


void Write()
{
	ofstream fout("rj.out");
/*
	for ( int i = 1; i <= m; i++ )
	{
		for ( int j = 1; j <= n; j++ )
			fout << setw(4) << R[i][j];
		fout << '\n';
	}
	fout << '\n';
	for ( int i = 1; i <= m; i++ )
	{
		for ( int j = 1; j <= n; j++ )
			fout << setw(4) << J[i][j];
		fout << '\n';
	}
*/
	int i, j;
	int tmin = INFINITY, imin = 0, jmin = 0;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			if ( R[i][j] == J[i][j] )
				if ( R[i][j] < tmin )
				{
					tmin = R[i][j] + 1;
					imin = i;
					jmin = j;
				}
	fout << tmin <<" " << imin << " "<< jmin << '\n';

	fout.close();
}

