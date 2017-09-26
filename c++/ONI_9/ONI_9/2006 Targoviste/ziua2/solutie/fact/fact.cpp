#include<stdio.h>
#define lmax 10000

FILE *fin,*fout;

void multiply(long x[lmax],long y,int b)
{
 long p[lmax],i,j,t,aux;

 p[0]=x[0];
 for(i=1;i<lmax;i++) p[i]=0;
 t=0;
 for(i=1;i<=x[0];i++)
  {
   p[i]=x[i]*y+t;
   t=p[i]/b;
   p[i]=p[i]%b;
  }
 while(t)
 {
  p[i]=t%b;
  t=t/b;
  i++;
 }
 p[0]=i-1;
 for(i=0;i<=p[0];i++) x[i]=p[i];
}

void print(long x[lmax])
{
 int i;

 i=1;
 while(!x[i]) i++;
 if(x[i]<10) fprintf(fout,"%ld\n",x[i]);
  else fprintf(fout,"%c\n",'A'+x[i]-10);
}

int main()
{
 long n,b,i,j;
 long x[lmax];

 fin=fopen("fact.in","r");
 fout=fopen("fact.out","w");
 for(i=1;i<=5;i++)
 {
  fscanf(fin,"%ld %ld",&n,&b);
  x[0]=x[1]=1;
  for(j=1;j<=n;j++)
   multiply(x,j,b);
  print(x);
  for(j=0;j<lmax;j++) x[j]=0;
 }
 fclose(fin);
 fclose(fout);
 return 0;
}
