#include <fstream.h>
#include <string.h>

int l[15];    // lungimile cuvintelor
int t[15];    // sirul tata
int a[100];   // a[i] - CLSC care se termina pe poz i
char cuv[100][100];
int n;
ofstream fout("cuv.out");

void Citeste();
void CLSC();
void Afiseaza();

int main()
{
	Citeste();
	CLSC();
	Afiseaza();

	return 0;
}
void Citeste()
{
	ifstream fin("cuv.in");
	int n = 0;
	while (! fin.eof() )
	{
		n++;
		fin >> cuv[n];
		l[n] = strlen(cuv[n]);
	}

	fin.close();
}

void CLSC()
{
	int i, j;
	for ( i = 1; i <= n; i++ )
	{
		a[i] = 1;
		t[i] = 0;
		for ( j = 1; j < i; j++ )
			if (  l[j] < l[i] && a[i] < a[j] + 1)
			{
				a[i] = a[j] + 1;
				t[i] = j;
			}
	}
}

void Afis(int k)
{
	if ( k == 0 ) return;
	Afis(t[k]);
	fout << cuv[k] << " ";
}

void Afiseaza()
{
	int max = a[1], k = 1;
	for ( int i = 1; i <= n; i++ )
		if ( a[i] > max )
		{
			max = a[i];
			k = i;
		}
	fout << max << endl;
	Afis( k );
	fout.close();
}

