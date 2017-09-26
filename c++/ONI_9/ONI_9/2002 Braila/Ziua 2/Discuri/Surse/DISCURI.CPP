
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 2
// Problema: Discuri

#include <stdio.h>
#include <math.h>

#define DIM 10000
#define GETCX(i,j) (x[j]+2*sqrt(r[i]*r[j])) // calculeaza abscisa centrului
                                            // cercului i (daca ar fi tangent la cercul j<i)

FILE *f=NULL;
int i=0,j=0,n=0,k=0,jm=0,jx=0;
float r[DIM]={0},x[DIM]={0},mx=0.0,ax=0.0; // r-razele cercurilor date, x-abscisele centrelor cercurilor
char s[DIM]={0}; // pt. marcarea cercurilor dispensabile
int main(int argc, char *argv[])
{
 f=fopen("DISCURI.IN","rt");
 fscanf(f,"%d",&n);
 for(i=0;i<n;fscanf(f,"%f",r+(i++)));
 fclose(f);
 for(i=0;i<n;i++)
 {
  mx=r[i],jm=-1;
  for(j=0;j<i;j++)
  {
    ax=GETCX(i,j);
    if(mx<ax) mx=ax,jm=j;
  }
  x[i]=mx;
  for(j=jm+1;j<i;j++)
    if(!s[j]) s[j]=1,++k;
  if(x[jx]+r[jx]<x[i]+r[i]) jx=i;
 }
 for(++jx;jx<n;jx++) if(!s[jx]) s[jx]=1,++k;
 f=fopen("DISCURI.OUT","wt");
 fprintf(f,"%d",k);
 for(i=0;i<n;i++) if(s[i]) fprintf(f,"\n%d",i+1);
 fclose(f);
 return 0;
}
