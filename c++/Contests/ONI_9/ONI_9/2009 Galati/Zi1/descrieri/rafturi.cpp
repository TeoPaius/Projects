#include <stdio.h>

#define MAXN 10000
#define MAXV 2000000000
int C;
long N;
int carti[MAXN+1];
long inaltime[MAXN+1];

void afisare(long a[MAXN+1])
{int i;
for(i=1;i<=C;i++)
	{printf("%ld",a[i]);
	}
  printf("\n");
}

void citire(void)
{
	FILE *f;
	int x,y;
	long i;

	f=fopen("rafturi.in","r");
	fscanf(f,"%d%ld",&C,&N);
	for (i=1;i<=N;i++)
	{
		fscanf(f,"%d%d",&y,&x);
		if (carti[y]<x) carti[y]=x;
	}
	carti[0]=0;
       // afisare(carti);
	fclose(f);
}

void calcul(void)
{	long h;
	int i,j;
	inaltime[0]=0;
	for (i=1;i<=C;i++)
	{
		inaltime[i]=MAXV+1;
		h=carti[i];
		if (inaltime[i-1]+h<inaltime[i])
			inaltime[i]=inaltime[i-1]+h;
		for (j=i-1; j>i-3 && j>0 ;j--)
		{
			if (h<carti[j]) h=carti[j];
			if (inaltime[j-1]+h<inaltime[i])
				inaltime[i]=inaltime[j-1]+h;
		}
	}
}

void afisare(void)
{
	FILE *g;
	g=fopen("rafturi.out","w");
	fprintf(g,"%ld\n",inaltime[C]);
	//printf("%ld\n",inaltime[C]);
	fclose(g);
}

int main()
{
	citire();
	calcul();
	afisare();
	return 0;
}
