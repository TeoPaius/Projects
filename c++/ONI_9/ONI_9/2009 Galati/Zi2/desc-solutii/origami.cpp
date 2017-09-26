#include <fstream.h>
#include <iostream.h>
#define Fin  "origami.in"
#define Fou  "origami.out"
#define Nmax 171

typedef int Foaie[Nmax][Nmax];
Foaie F;			//foaia de hartie

void indoaie(int &N, int &M, int Tip, int Lin)
{
	int i,j, k ,CatIndoi, Rest, tmp;
	if(Tip==1)
	{
		//daca indoitura depaseste cumva marginea dreapta a foii
		if(2*Lin>M)
		{
			CatIndoi = M - Lin;   		//numarul de coloane ale indoiturii
			Rest     = Lin - CatIndoi;	//cate coloane mut la sfarsit
		}
		else
		{
			CatIndoi = Lin;
			Rest	 = 0;
		}
		//copiez primele Rest coloane, oglindite, la sfarsitul tabloului, deplasand elem la stanga
		for(k=Rest;k>=1;k--)
			for(i=1;i<=N;i++)
			{
				tmp = F[i][k];
				for(j=k;j<M;j++) F[i][j] = F[i][j+1];
				F[i][M] = tmp;
			}	
		//indoi
		for(j=1;j<=CatIndoi;j++)
			for(i=1;i<=N;i++) F[i][2*CatIndoi-j+1] += F[i][j]; 
		//mut elementele tabloului cu CatIndoi elemente la stanga
		for(i=1;i<=N;i++)
			for(j=1;j<=M-CatIndoi;j++) F[i][j] = F[i][j+CatIndoi];
		M = M - CatIndoi;
	}
	else
	{
		//daca indoitura depaseste cumva marginea de jos a foii
		if(2*Lin>N)
		{
			CatIndoi = N - Lin;   		//numarul de coloane ale indoiturii
			Rest     = Lin - CatIndoi;	//cate coloane mut la sfarsit
		}
		else
		{
			CatIndoi = Lin;
			Rest	 = 0;
		}
		//copiez primele Rest linii, oglindite, la sfarsitul tabloului, deplasand liniile in sus
		for(k=Rest;k>=1;k--)
			for(i=1;i<=M;i++)
			{
				tmp = F[k][i];
				for(j=k;j<N;j++) F[j][i] = F[j+1][i];
				F[N][i] = tmp;
			}	
		//indoi
		for(i=1;i<=CatIndoi;i++)
			for(j=1;j<=M;j++) F[2*CatIndoi-i+1][j] += F[i][j]; 
		//mut elementele tabloului cu CatIndoi elemente in sus
		for(i=1;i<=N-CatIndoi;i++)
 			for(j=1;j<=M;j++)F[i][j] = F[i+CatIndoi][j];
		N = N - CatIndoi;
	}
}

int main()
{
	ifstream f(Fin);
	int N;				//dimensiunea initiala a  hartiei
	int M;				// latimea hartiei, initial = N
	int Nr;				//numarul indoiturilor

	int Tip;			//Tipul indoiturii: 1 verticala spre dreapta; 2 - orizontal de sus in jos
	int Lin;			//Linia de-a lungul careia facem indoitura
	int Max;			//Grosimea maxima
	int i,j;
	//citesc datele de intrare si indoi
	f>>N>>Nr;
	M = N;				//initial hartia e patrata, pe urma nu
	//initializez hartia
	for(i=1;i<=N;i++) for(j=1;j<=M;j++) F[i][j] = 1;
	for(i=1;i<=Nr;i++)
	{
		f>>Tip>>Lin;
		indoaie(N,M,Tip,Lin);
	}
	f.close();
	//aflu grosimea maxima si afisez datele de iesire
	Max = 0;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(F[i][j]>Max) Max = F[i][j];
	ofstream g(Fou);
	g<<N<<" "<<M<<" "<<Max<<'\n';
	/*
    for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++) g<<F[i][j]<<" ";
		g<<'\n';
	}
	*/
	g.close();
	return 0;
}
