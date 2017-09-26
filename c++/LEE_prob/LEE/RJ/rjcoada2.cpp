#include <fstream>
#include <iomanip>
using namespace std;


const int DIM = 101;

int m, n;
int modificare, pas;
const int  INFINIT = 10000;
char a[DIM][DIM];
int R[DIM][DIM];
int J[DIM][DIM];
int iR, jR, iJ, jJ;
int iv, jv;

int c[DIM*DIM][2], prim, ultim;

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
	if ( c[iv][jv] < INFINIT )return 0; // am mai calcat
	if ( a[iv][jv] == 'X' ) return 0;    // obstacol
	return 1;
}


void Lee(int d[][DIM], int is, int js)
{
	int i = 0, j = 0;

	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			d[i][j] = INFINIT;
	d[is][js] = 0;    // initializare OBLIGATORIE

	for ( c[prim = ultim = 0][0] = is, c[ultim][1] = js; prim <= ultim; prim++ )
    {
        i = c[prim][0];           // (i, j) elementul din capul cozii
        j = c[prim][1];
        for ( int dir = 0; dir < 8; dir++ )    
		{
			iv = i + di[dir];    // vecinii elem din capul cozii
			jv = j + dj[dir];
			if ( OK( d ) && d[iv][jv] > d[i][j] + 1)   // daca sunt nemarcati
			{
			    d[iv][jv] = d[i][j] + 1;             // se marcheaza 
			    c[++ultim][0] = iv;                  // se introduc in coada 
			    c[ultim][1] = jv;
            }
        }
    }        		  			    
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
	int tmin = INFINIT, imin = 0, jmin = 0;
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

