#include <iostream.h>
#include <conio.h>
#include <stdio.h>
int a[101][101],m,n,k,l0,l1,c0,c1,x,y;
int s[4];
FILE *g;
int generare(int lin, int col)
{
	int ax[101][101],i,j,ok;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			ax[i][j]=0;
	for(j=1;j<=n;j++)//pun coloanele care trebuie   pe 1
		if(a[1][j]==lin)
			for(i=1;i<=m;i++)
				ax[i][j]=1;
	for(i=1;i<=m;i++)//comut liniile care trebuie
		if(a[i][1]==col)
			for(j=1;j<=n;j++){
				if(ax[i][j]==0) ax[i][j]=1;
				else ax[i][j]=0;
			}
	//verificare
	ok=1;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(ax[i][j]!=a[i][j])
				ok=0;
		}
 return ok;
}
void comutare(int lin,int col)
{    int i,j;
		//cout<<"\nmodific  coloanele "<<endl;
      int sw=1;
		for(j=1;j<=n;j++) if (a[1][j]==lin)
      { fprintf(g,"%d ",j);sw=0;
       //solc[jj++]=j;
      }
       if (sw) fprintf(g,"0");
		//cout<<"\nmodific liniile "<<endl;
      fprintf(g,"\n");
       sw=1;
		for(i=1;i<=m;i++)
          if (a[i][1]==col)
           {fprintf(g,"%d ",i);
            sw=0;}
       if (sw) fprintf(g,"0");
             fprintf(g,"\n");
}

int date_valide()
{
	int sir[101],i,j,egale,opuse;
	for(i=1;i<=m;i++) sir[i]=0;
	sir[1]=1;
   for(i=2;i<=m;i++)
   {
     egale=1;//presupun ca sunt egale
     for (j=1;j<=n;j++)
       if (a[1][j]!=a[i][j])
          {
            egale=0;
            j=n+1;
           }

    if (egale==0)//verific daca sunt opuse
     {
       opuse=1;//presupun ca sunt opuse
      for (j=1;j<=n;j++)
       if (!(a[1][j]^a[i][j]))
          {
            opuse=0;
            j=n+1;
          }
      }
    if (egale==1 || opuse==1) sir[i]=1;
       else sir[i]=0;
 }
for(i=1;i<=m;i++)
  if (sir[i]==0) return 0;
return 1;
}

void citire_fis(){
	FILE *f;
	int i,j;
	f=fopen("becuri.in","r");
	fscanf(f,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			fscanf(f,"%d",&a[i][j]);
			if(a[i][j]) k++;
		}
	fclose(f);
}
void main(){
int test,i,j,min,k1=0,k2=0,k3=0,k4=0;
g=fopen("becuri.out","w");
citire_fis();
test=date_valide();
if (!test)
	fprintf(g,"-1");
for(j=1;j<=n;j++)
	if(a[1][j]) l1++;
l0=n-l1;
for(i=1;i<=m;i++)
	if(a[i][1]) c1++;
c0=m-c1;
i=0;
 if (generare(0,0)) {i++;s[i]=l0+c0;k1=1;}
 if (generare(0,1)) {i++; s[i]=l0+c1;k2=1;}
if (generare(1,0)) {i++;s[i]=l1+c0;k3=1;}
if (generare(1,1)) {i++;s[i]=l1+c1;k4=1;}

if (s[1]<s[2]) min=s[1];
  else min=s[2];

if (min==l0+c0 && k1) comutare(0,0);
else
if (min==l0+c1 && k2) comutare(0,1);
else
if (min==l1+c0 && k3) comutare(1,0);
else
if (min==l1+c1 && k4) comutare(1,1);
fclose(g);
}