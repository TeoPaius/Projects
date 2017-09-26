/*		Det comp. tare conexe a unui graf orientat

Def. Un graf este tare conex <=> intre oricare doua noduri i si j ale sale
     exista cel putin un drum, atat de la i la j cat si de la j la i


   - matr.de adiacenta se transf.in matricea drumurilor cu alg. Roy-Warshall
   - pt. fiec. nod k neincadrat intr-o componenta tare conexa se creaza o no-
	ua comp. tare conexa care va contine nodul k si toate nodurile i pt.
	care exista un drum de la k lai si un drum de la i la k;
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[30][30],v[30],nr,n,m;


void Citire();
void Roy_Warshall();
void Comp_Tare_Conexe();

main()
{
	clrscr();
	Citire();
	Roy_Warshall();
	Comp_Tare_Conexe();

	return 0;
}

void Citire()
{
	FILE *f;
	int i,j,k;
	if(!(f=fopen("c:\\tu\\structur\\grafuri\\in.txt","r")))
	{
		printf("Nu pot desch.fisierul.");
		exit(1);
	}
	//initializari
	for(i=1;j<=n;k++)
		for(j=0;j<=n;j++)
			a[i][j]=0;

	fscanf(f,"%d %d",&n,&m);
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d %d",&i,&j);
		a[i][j]=1;
	}
}

void Roy_Warshall()
{
	int k,i,j;

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if((a[i][k]==1)&&(a[k][j]==1))
					a[i][j]=1; //drumul de la i la j exista
//a[i][j] devine matricea drumurilor
}

void Comp_Tare_Conexe()
{
	for(int i=1;i<=n;i++)
		v[i]=0;

	printf("\nComponentele tare conexe sunt :\n");

		for(int k=1;k<=n;k++)
			if(!v[k])
			{
				for(i=1;i<=n;i++)
					if(a[k][i]==1  && a[i][k]==1)
					{
						v[i]=1;
						printf("%d ",i);
					}
				printf("\n");

			}
}





