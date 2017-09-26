//Serban Marinel
//februarie 2012
#include <fstream>
#define DIM 1001

using namespace std;

ifstream fin("triunghi.in");
ofstream fout("triunghi.out");

int N, p[DIM];
unsigned long long L1[DIM], L2[DIM], v[DIM];

void citire()
{
	int i;
	fin >> N;
	for (i = N; i >0; i--)           //le citesc invers ca sa lucrez
		fin >> p[i] >> v[i];         //"mai usor" la reconstruire
	fin.close();
}

void refa()
{
	int i, j;
	for (i = 2; i <= N; i++)  //refa linia i (de sus in jos)
	{
		L2[p[i]] = v[i];                     //pun in L2 valoarea cunoscuta
		if (p[i] > p[i - 1])                 //detectez sensul recalcularii
		{
			for (j = p[i] - 1; j > 0 ; j--)  //intai spre stanga
				L2[j] = L1[j] - L2[j + 1];
			for (j = p[i] + 1; j <= i; j++)  //apoi spre freapta
				L2[j] = L1[j - 1] - L2[j - 1];
		}
		else
		{
			for (j = p[i] + 1; j <= i; j++)   //intai spre dreapta
				L2[j] = L1[j - 1] - L2[j - 1];
			for (j = p[i] - 1; j > 0; j--)    //apoi spre stanga
				L2[j] = L1[j] - L2[j + 1];
		}
		for (j = 1; j <= i; j++)              //copiez L2 in L1
			L1[j] = L2[j];                    //adica L2 devine L1
		for (j = 1; j <= i; j++)              //"curat" L2
			L2[j] = 0;                        //nu era neaparat necesar
	}
}

void afisare()
{
	int i;
	for (i = 1; i < N; i++)          //afisez primele N-1 valori
		fout << L1[i] << ' ';        //urmate de un spatiu
	fout << L1[N] << '\n';           //apoi ultima valoare urmata de ENTER
}

int main()
{
	citire();
	L1[1] = v[p[1]];
	refa();
	afisare();
	fout.close();
	return 0;
}
