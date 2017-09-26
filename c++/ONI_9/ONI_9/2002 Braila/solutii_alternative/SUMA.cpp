
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 1
// Problema: Suma

#include <stdio.h>
#include <math.h>

FILE *f=NULL;
long s=0,n=0,x=0;
int main(int argc, char *argv[])
{
 f=fopen("SUMA.IN","rt");
 fscanf(f,"%ld",&s); fclose(f);
 f=fopen("SUMA.OUT","wt");
 n=sqrt(1+8*s);
 if(n*n==1+8*s) fprintf(f,"%ld",(n-1)/2);
 else
 {
 	 --n/=2;
	 x=n*(n+1)/2;
	 x=x+n+1-s;
	 if(x&1)
	 {
			 n+=2;
			 if(n&1) fprintf(f,"%ld\n1\n%ld\n%ld",n,(x-1)>>1,(n-1)>>1);
			 else fprintf(f,"%ld\n1\n%ld\n%ld",n+1,(x-1)>>1,n);
	 }
	 else fprintf(f,"%ld\n%ld",n+1,x>>1);
 }
 fclose(f);
 return 0;
}
