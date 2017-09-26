#include <fstream>
#include <iomanip>
using namespace std;

#define BIG 10000
#define IN  "hercule.in"
#define OUT "hercule.out"

const int DIM = 101;

int m, n;

int tp[DIM][DIM];     // timpii de cadere a pietrelor
int t[DIM][DIM];

int ip, jp, is, js;   // plecare, sosire
int iv, jv;
int c[DIM*DIM][2], prim, ultim;

const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
ofstream fout(OUT);

int Lee();
void Read();
void Write();
int OK(int i, int j);
void  Path(int i, int j);

int main()
{
	Read();
	if ( !Lee() ) fout <<"-1\n";
//	Write();   // Debug
    fout.close();
	return 0;
}

void Read()
{
	ifstream fin(IN);
	fin >> m >> n;

	for ( int i = 1; i <= m; i++ )
		for ( int j = 1; j <= n; j++ )
		{
            fin >> tp[i][j];
            t[i][j] = t[j][i] = BIG;
		}
    fin >> ip >> jp >> is >> js;

	fin.close();
}

int OK(int i, int j)
{
	if ( iv < 1 || iv > m || jv < 1 || jv > n ) return 0;  // in afara matricii
	if ( t[iv][jv] < BIG ) return 0; // am mai calcat
	if ( t[i][j] + 1 >= tp[iv][jv] ) return 0;    // obstacolul cade inainte 
	return 1;                                     // sa ajunga Hercule
}

int Lee()
{
	int i = 0, j = 0;

    t[ip][jp] = 0;

	prim = ultim = 0;
	c[ultim][0] = ip;      // pozitia de plecare se introduce in coada
	c[ultim][1] = jp;
    while ( prim <= ultim )
    {
        i = c[prim][0];           // (i, j) elementul din capul cozii
        j = c[prim][1];
        for ( int dir = 0; dir < 8; dir++ )    
		{
			iv = i + di[dir];    // vecinii elem din capul cozii
			jv = j + dj[dir];
			if ( OK(i, j) )   // daca sunt nemarcati si nu e bloc
			{
				t[iv][jv] = t[i][j] + 1;             // se marcheaza
				if ( iv == is && jv == js )
				{
					fout << t[iv][jv] << "\n";
					Path(iv, jv);
					return 1;   // ies din Lee()
				}
				c[++ultim][0] = iv;                  // se introduc in coada
				c[ultim][1]   = jv;
			}
		}
		prim++;
	}
	return 0;
}

void Write()
{
	int i, j;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
			fout << setw(5) << t[i][j];
		fout << '\n';
	}
	fout << '\n';
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= n; j++ )
			fout << setw(4) << tp[i][j];
		fout << '\n';
	}
}

int Inside()
{
	return iv >= 1 && iv <= m && jv >= 1 && jv <= n;
}

void Path(int i, int j)
{
	if ( i == ip && j == jp ) return;

	for ( int d = 0; d < 8; d++ )
	{
		iv = i + di[d];
		jv = j + dj[d];
		if ( Inside() && t[iv][jv] + 1 == t[i][j] )
		{
			Path(iv, jv);
			fout << i << " " << j << "\n";
			break;
		}
	}
}


                                        
