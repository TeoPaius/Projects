
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 1
// Problema: Pod

#include <stdio.h>

#define DIM 300

typedef unsigned long Huge[100];

FILE *f=NULL;
int s[DIM+2]={0},n=0,k=0,h=0,i=0;
Huge nr[DIM+2]={0};
void rc(int);
int main(int argc, char *argv[])
{
 f=fopen("POD.IN","rt");
 fscanf(f,"%d %d",&n,&k);
 for(i=0;i<k;i++)
 {
 	fscanf(f,"%d",&h);
	s[h]=1;
 }
 fscanf(f,"%d",&h);
 for(i=0;i<h;i++)
 {
 	fscanf(f,"%d",&k);
	s[k]=2;
 }
 fclose(f);
 nr[0][0]=nr[0][1]=1;
 if(s[1]!=1) nr[1][0]=nr[1][1]=1;
 if(s[2]!=1)
	if(!s[2])
		if(s[1]!=1) nr[2][0]=1,nr[2][1]=2;
		else nr[2][0]=nr[2][1]=1;
	else if(s[1]!=1) nr[2][0]=1,nr[2][1]=1;
 for(i=3;i<=n+1;i++)
 	if(s[i]!=1)
		if(!s[i])
		{
			for(k=0;k<=nr[i-1][0];k++) nr[i][k]=nr[i-1][k];
			unsigned long T=0;
			if(!s[i-2])
			{
				for(k=1;k<=((nr[i][0]>nr[i-2][0])? nr[i][0]:nr[i-2][0]);k++)
					nr[i][k]=(T+=nr[i][k]+nr[i-2][k])%10,T/=10;
				while(T) nr[i][k++]=T%10,T/=10;
				nr[i][0]=k-1;
			}
			if(!s[i-3])
			{
				for(k=1;k<=((nr[i][0]>nr[i-3][0])? nr[i][0]:nr[i-3][0]);k++)
					nr[i][k]=(T+=nr[i][k]+nr[i-3][k])%10,T/=10;
				while(T) nr[i][k++]=T%10,T/=10;
				nr[i][0]=k-1;
			}
		}
		else
			for(k=0;k<=nr[i-1][0];k++) nr[i][k]=nr[i-1][k];
 f=fopen("POD.OUT","wt");
 if(nr[n+1][0])
 {
 	for(i=nr[n+1][0];i;i--) fprintf(f,"%lu",nr[n+1][i]);
	fprintf(f,"\n");
	if(nr[n][0]) rc(n);
	else if(nr[n-1][0] && !s[n-1]) rc(n-1);
	else rc(n-2);
 }
 else fprintf(f,"-1");
 fclose(f);
 return 0;
}
void rc(int x)
{
	if(x==1) fprintf(f,"1");
	else if(x==2 && !s[2]) fprintf(f,"2");
  else if(x==3 && !s[3]) fprintf(f,"3");
	else
	{
		if(nr[x-1][0]) rc(x-1);
		else if(nr[x-2][0] && !s[x-2])	rc(x-2);
		else rc(x-3);
		fprintf(f," %d",x);
	}
}
