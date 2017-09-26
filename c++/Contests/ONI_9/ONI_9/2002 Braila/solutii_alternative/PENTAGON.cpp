
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 1
// Problema: Pentagon

#include <stdio.h>

#define DIM 200

FILE *f=NULL;
int i=0,j=0,k=0,m=0,n=0;
unsigned char a[DIM][DIM]={0};
unsigned int h[DIM+1]={0};
int main(int argc, char *argv[])
{
 f=fopen("PENTAGON.IN","rt");
 fscanf(f,"%d %d",&m,&n);
 for(i=0;i<m;i++)
 	for(j=0,fscanf(f,"%c",&(a[i][0]));j<n;j++)
	{
		fscanf(f,"%c",&(a[i][j]));
		a[i][j]-='0';
	}
 fclose(f);
 for(i=0;i<n;i++)
 {
 	for(j=k=0;j<m;j++)
		if(a[j][i])
			{ if(k) ++h[k],k=0; }
		else ++k;
	if(k) ++h[k],k=0;
 }
 f=fopen("PENTAGON.OUT","wt");
 for(i=1;i<=m;i++)
 	if(h[i]) fprintf(f,"%d %u\n",i,h[i]);
 fclose(f);
 return 0;
}
