#include <fstream.h>

int a[50][50];  // matr adiacenta
int n, m;   // nr nodur, nr muchii
int suc[50];   // sirul succesorilor
// suc[i] = j  i este succesor al lui j
int pred[50];  // // sirul prdecesorilor
// pred[i] = j  i este predecesor al lui j



int nrc; // nr de componente conexe
ofstream fout("graf.out");

void Citeste(char nume[]);
void DFSucc(int nod);
void DFPred(int nod);
void CompConexe();



int main()
{
	Citeste("graf.in");
	CompConexe();
	fout.close();


	return 0;
}

void Citeste(char nume[])
{
	ifstream fin(nume);
	int v1, v2;
	fin >> n >> m;
	for ( int i = 1; i <= m; i++ )
	{
		fin >> v1 >> v2;
		a[v1][v2] = 1;
	}
	fin.close();
}

void DFSucc(int nod)
{
	suc[nod] = nrc;          // il selectez
	for ( int i = 1; i <= n; i++ )
		if ( a[nod][i] == 1 && suc[i] == 0)  // gasesc primul vecin neselectat
			DFSucc( i );
}


void DFPred(int nod)      // DF pe graful Transpus (arcele inversate)
{
	pred[nod] = nrc;          // il selectez
	for ( int i = 1; i <= n; i++ )
		if ( a[i][nod] == 1 && pred[i] == 0)  // am arc de la i la nod
			DFPred( i );
}



void CompConexe()
{
	for ( int i = 1; i <= n; i++ )
		if ( suc[i] == 0 ) // o noua com tare conexa
		{
			nrc++;
			DFSucc(i);       // O(m)
			DFPred(i);
			fout << "Comp tare conexa nr " << nrc << ": ";
			for ( int j = 1; j <= n; j++ )
				if ( suc[j] == nrc && pred[j] == nrc )
					fout << j << " ";
				else  if ( suc[j] == 0 || pred[j] == 0 )
						suc[j] = pred[j] = 0;
			fout << endl;
		}
}


