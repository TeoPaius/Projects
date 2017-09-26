/*  Pe o tabla de sah, de dimensiune standard 8x8, se afla diverse
	piese de sah. Un cal se afla in pozitia (i, j). Dorim sa mutam
	calul din pozitia (k, l)-daca acest ;lucru este posibil, folosind
	oricare din cele 8 mutari posibile ale calului in orice succesiune,
	astfel incat numarul de mutari sa fie minim. Sa se det. nr minim
	de mutari.
*/
//numarul minim de mutari intre doua pozitii date (# - permis, * - interzis)
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define INFINIT 65



struct Tata {
	int i, j;
} tata[9][9];


ofstream fout("tabla.out");
char t[9][9];  //tabla(matricea cu obstacole)

int a[9][9]; // a[i][j] - nr min mutari pt a ajunge in poz (i, j)
int pas, i, j, k, l, is, js, ifi, jfi, modificare;
const int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dj[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


void Citeste();
void Afis(int i, int j);
int PoateSari(int k, int l);
void Marcheaza(int i, int j);
void Lee();
void Afiseaza();

int main()
{
	Citeste();
	Lee();
	Afiseaza();

	return 0;
}

void Citeste()
{
	ifstream fin("tabla.in");
	if ( !fin   )
	{
		cout << "nu gasesc intrarea!";
		exit(1);
	}
	fin >> is >> js >> ifi >> jfi; // coord de plecare si sosire
	for ( int i = 1; i <= 8; i++ )           // O(n^2)
		for ( int j = 1; j <= 8; j++ )
		{
			fin >> t[i][j];
			a[i][j] = INFINIT;
		}

	if ( t[is][js] == '*' || t[ifi][jfi] == '*' )
	{
		cout << "deplasare imposibila!\nPozitie finala ocupata!";
		exit(1);
	}
	fin.close();
}


void Afis(int i, int j)
{
	if ( tata[i][j].i == 0 && tata[i][j].j == 0 ) return;
	Afis( tata[i][j].i, tata[i][j].j );
	fout  << i << " " << j << endl;

}

void Afiseaza()
{
	if ( a[ifi][jfi] == INFINIT ) fout << "Deplasare imposibila!";
		else fout << "Deplasarea din (" << is << ", " << js <<") in (" << ifi << ", " << jfi
			   <<") \nse poate face in " << a[ifi][jfi] << " mutari";

	Afis(ifi, jfi);
	fout.close();
}

int PoateSari( int k, int l)
{
	if ( k >= 1 && k <= 8 && l >= 1 && l <= 8 && t[k][l] == '#' && a[k][l] == INFINIT ) return 1;
	return 0;
}

void Marcheaza(int i, int j)
{
	a[i][j] = pas + 1;
	modificare = 1;
}

void Lee()
{
	a[is][js] = 0; pas = 0; modificare = 1;
	while ( modificare )
	{
		modificare = 0;
		for ( i = 1; i <= 8; i++ )
			for ( j = 1; j <= 8; j++ )
				if ( a[i][j] == pas )
				for ( int p = 0; p < 8; p++ )
				{
					k = i + di[p];
					l = j + dj[p];
					if ( PoateSari(k, l) ) Marcheaza(k, l);

					if ( a[ifi][jfi] != INFINIT ) // s-a ajuns la pozitia finala ( mai elegant return )
					{
						i = 9; j = 9;     // nu se mai calculeaza restul matricei
						p = 8;      // setez pe fals conditiile ciclurilor
						modificare  = 0;
						// return; // mai simplu
					}
				}
		pas++;
	}
}
