/*  Pe o tabla de sah, de dimensiune standard 8x8, se afla diverse
	piese de sah. Un cal se afla in pozitia (i, j). Dorim sa mutam
	calul din pozitia (k, l)-daca acest ;lucru este posibil, folosind
	oricare din cele 8 mutari posibile ale calului in orice succesiune,
	astfel incat numarul de mutari sa fie minim. Sa se det. nr minim
	de mutari si traseul calului.
*/
//numarul minim de mutari intre doua pozitii date (# - permis, * - interzis)
//afiseaza si traseul pe drumul cel mai scurt
#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>


char t[9][9];  //indexeaza de la 1

int a[9][9]; // a[i][j] - nr min mutari pt a ajunge in poz (i, j)
int pas, i, j, k, l, ic, jc, kc, lc, modificare;
const int di[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dj[] = { 1, 2, 2, 1, -1, -2, -2, -1 };


void Citeste();
int PoateSari(int k, int l);
void Marcheaza(int i, int j);
void Lee();
void Afiseaza();

ofstream g("tabla.out");
int main()
{
	Citeste();
	Lee();
	Afiseaza();
	g.close();

	return 0;
}

void Citeste()
{
	ifstream f("tabla.in");
	if ( !f )
	{
		cout << "nu gasesc intrarea!";
		exit(1);
	}
	f >> ic >> jc >> kc >> lc;
	for ( int i = 1; i <= 8; i++ )
		for ( int j = 1; j <= 8; j++ )
		{
			f >> t[i][j];
			a[i][j] = 65;
		}

	if ( t[ic][jc] == '*' || t[kc][lc] == '*' )
	{
		cout << "deplasare imposibila!\nPozitie finala ocupata!";
		exit(1);
	}
	f.close();
}

void Afis(int i, int j)
{
	if ( i == ic && j == jc ) 
    {
        g << i << "  " << j << '\n';
        return;
    }    
    for ( int d = 0; d < 8; d++ )
    {
	   int iv = i + di[d];
       int jv = j + dj[d];
       if ( a[iv][jv] + 1 == a[i][j] )  
       {
            Afis( iv, jv );
            g  << i << " " << j << endl;
    //        return;
       }   
    }	   
}

void Afiseaza()
{

	if ( a[kc][lc] == 65 ) g << "Deplasare imposibila!";
		else g << "Deplasarea din (" << ic << ", " << jc <<") in (" << kc << ", " << lc
			   <<") \nse poate face in " << a[kc][lc] << " mutari" << endl;

	 Afis(kc, lc);
}

int PoateSari( int k, int l)
{
	if ( k >= 1 && k <= 8 && l >= 1 && l <= 8 && t[k][l] == '#' && a[k][l] > pas) return 1;
		else return 0;
}

void Marcheaza(int i, int j)
{
	a[i][j] = pas + 1;
	modificare = 1;
}

void Lee()
{
	a[ic][jc] = 0; pas = 0; modificare = 1;
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
					if ( PoateSari(k, l) )

						Marcheaza(k, l);

					if ( a[kc][lc] != 65 ) return;
				}
		pas++;
	}
}
