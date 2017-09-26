#include <fstream.h>
short int c[256];   //
char n[10];
long int s[10000];
char x[256];        // codul
long int k;

ifstream fin("seti.in");
ofstream fout("seti.out");

long int i, p;
int main()
{
	fin >> x;     // codul de carctere
	for (i = 0; i < 10; i++ )
	{
		c[x[i]] = i;   // caracterului x[i] ii coresp cifra i
  		n[i] = x[i];   // si invers: cifrei i ii coresp caracterul x[i]
	}

	while (/* !fin.eof() */ fin >> x)
	{
   		     // cuvantul
   		p = c[x[0]] * 1000 + c[x[1]] * 100 + c[x[2]] * 10 + c[x[3]]; // construieste un numar din cifre
   		s[p]++;        // frecventa de aparitie a cuvantului x caruia ii coresp numarul p
	}
	fin.close();

	for (p = 0; p < 10000; p++ )
	if ( s[p] )
  		for (k = 1; k <= s[p]; k++ ) // daca am mai multe cuvinte identice le scriu consecutiv sau pt s[p] = 0 - deloc
  			fout << n[p / 1000] << n[(p / 100) % 10] << n[(p / 10) % 10] << n[p %10] << "\n";

	fout.close();
	return 0;
}

