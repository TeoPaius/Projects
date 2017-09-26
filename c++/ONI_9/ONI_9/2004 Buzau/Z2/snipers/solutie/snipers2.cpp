#include <fstream.h>


const int NMAX = 1000;

struct Coord {
	long int x, y, k;  // coord. si pe cine kill-ere
};

Coord t[NMAX], c[NMAX]; // tragatori si capetenii
int n;

void Citire();
double S(Coord p, Coord a, Coord b);
int Inter(Coord a1,Coord b1, Coord a2, Coord b2);
void Rezolva();
void Scrie();

int main()
{
	Citire();
	Rezolva();
	Scrie();
	return 0;
}

void Citire()
{
	int i;
	memset(t, 0, sizeof(t));
  	memset(c, 0, sizeof(c));
  	ifstream fin("snipers.in");

  	fin >> n;
  	for (i = 1; i <= n; i++)      // tragatorii
  		fin >> t[i].x >> t[i].y;

  	for (i = 1; i <= n; i++)     // capeteniile
    	fin >> c[i].x >> c[i].y;

  	fin.close();
}

void Scrie()
{
	int i;
	ofstream fout("snipers2.out");
	for ( i = 1; i <= n; i++ )
    	fout << t[i].k << '\n';
     fout.close();
}

//ne spune de ce parte a dreptei ce trece prin a, b se afla punctul p
double S(Coord p, Coord a, Coord b)
{
	return (double)p.y * (b.x - a.x) - (double)p.x * (b.y - a.y) + (double)a.x * b.y - (double)b.x * a.y;
}

//testeaza daca segmentul[a1,b1] se intersecteaza cu [a2,b2]
int Inter(Coord a1,Coord b1, Coord a2, Coord b2)
{
	return S(a2, a1, b1) * S(b2, a1, b1) < 0 &&
 		   S(a1, a2, b2) * S(b1, a2, b2) < 0;
}
/* a2 si b2 se afla de o parte si de alta a lui [a1,b1]
  si
  a1 si b1 se afla de o parte si de alta a lui [a2,b2] }
*/

void Rezolva()
{
	int i, j, aux, e_int, ok;
	for (i = 1; i <= n; i++)
		t[i].k = i;    // tragatorul i trage in capetenia i, pentru inceput

	if ( n > 1 )
		do
		{
			for ( ok = 1, i = 1; i < n; ) //am gasit o combinatie valida tragator-capetenie
			{
      			for (e_int = 0, j = i + 1; j < n && !e_int; j++ )
      			{
        			e_int = Inter(t[i], c[t[i].k], t[j], c[t[j].k]); // cu traiectoria de la sniper j la tinta sa }

        			if ( e_int )        // daca da le interschimbam tintele, si
          			{
						aux = t[i].k;
						t[i].k = t[j].k;
						t[j].k = aux;
						ok = 0;           // notam ca nu avem o combinatie buna
					}
      			 }
      			 if ( !e_int ) i++;   // daca nu jeneaza pe numeni trecem la urmatorul sniper}
            }    

  		} while ( !ok );
}

