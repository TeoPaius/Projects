#include <fstream>
using namespace std;

#include <stdlib.h>

#define NODS  100UL
#define KMAX  1001UL
#define NIL   255
#define IN    "ARBORE.I4"
#define OUT   "arbore.out"


typedef struct nod
{
	int left;
	unsigned char down;
} NOD, *PNOD;

ifstream fin(IN);
ofstream fout(OUT);
int n, k;

NOD **p;
int tata[NODS];
int val[NODS];

void End();
void Solution();
void Postord(int nod);   // DF()


int main()
{
	unsigned long i,j;

	fin >> n >> k;
	p = new PNOD [n + 1];
	for ( i = 0; i <= n; i++ )
		p[i] = new NOD [k + 1];
		
	tata[0] = NIL;
	fin >> val[0];
	for (i = 1; i < n; i++)
	{
		fin >> tata[i] >> val[i];
		tata[i]--;
	}

	Postord(0);
	fout <<"-1\n";
	End();
	return 0;
}

void End()
{
	for ( int i = 0; i <= n; i++ )
		delete [] p[i];
	delete [] p;
	fin.close();
	fout.close();
	exit(0);
}

void Solution(int nod,int valoare)
{
	int v = valoare;
	fout << nod + 1 << "\n";
	while ( p[nod][v].down != NIL )
	{
		Solution(p[nod][v].down, v - p[nod][v].left ); // down e fiul lui nod; valoarea lui e valoare - cat avea nod initial(fara down)
		v = p[nod][v].left;        //suma fara fiul down
	}
}

void Postord(int nod)
{
	int f, i, j;	 // OBLIGATORIU LOCALE

	for (f = 0; f <= k; f++)
	{                     // left  - Suma pe care o avea, inainte sa luam ceva de la fiul down
		p[nod][f].left = -1; // suma i n-a fost obtinuta
		p[nod][f].down = NIL;   // pt nici o suma nu s-au luat fii i
	}
	p[nod][val[nod]].left = 0;    // val[nod] se adauga peste 0  (s-a putut obtine suma val[nod])
	p[nod][val[nod]].down = NIL;  // n-are fii
	if (val[nod] == k)
	{
		Solution(nod ,k); // doar afiseaza nodul nod ( nu intra in ciclul while )
		End();
	}
	for (f = 0; f < n; f++)
		if (tata[f] == nod) // muchie  f e fiu
		{
			Postord( f ); // am rezolvat linia fiului f (in matricea p[][])
			for (i = 0; i <= k; i++)
				if ( p[nod][i].left >= 0 ) // a putut fi obtinuta suma i
					for (j = 0; j <= k - i; j++)   // j <= k - i
						if ( p[f][j].left >= 0 &&  // s-a obtinut suma j pe linia i
							 p[nod][i].down != f && // n-am mai folosit subarborele cu rad in i pt obtinerea sumei i
							 p[nod][i+j].left <= 0 )   // i+j neobtinuta inca
						{
							p[nod][i+j].left = i;   // left - suma (i) peste care s-a adaugat j ca sa rezulte i + j
							p[nod][i+j].down = f;  // i rad subarb care a fost folosit ultima data pt obt sumei i + j
							if ( i + j == k)
							{
								Solution(nod, k); // Afisez nodurile care contribuie
								End();   // la suma k, din subarb cu rad in nod
							}
						}
		}
}

