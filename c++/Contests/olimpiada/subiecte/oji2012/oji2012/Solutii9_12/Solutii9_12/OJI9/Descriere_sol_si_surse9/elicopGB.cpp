#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,Teren[101][101],E_Sol[101],Elicop[41][5],k,nre,Caz,nr_umbra;
FILE *f,*g;
void citire()
{fscanf(f,"%d%d",&m,&n);
for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		fscanf(f,"%d",&Teren[i][j]);
fscanf(f,"%d",&k);
for(int i=1;i<=k;i++)
	fscanf(f,"%d%d%d%d%d",&Elicop[i][1],&Elicop[i][2],&Elicop[i][3],&Elicop[i][4],&Elicop[i][0]);
fclose(f);
}
int main()
{f=fopen("elicop.in","r");
g=fopen("elicop.out","w");
nre=0;
citire();
int nr1;
for(int i=1;i<=k;i++)
{
	if((Elicop[i][3]-Elicop[i][1])*(Elicop[i][4]-Elicop[i][2])>0&&Elicop[i][0]==-1)Caz=1;
	else
		if((Elicop[i][3]-Elicop[i][1])*(Elicop[i][4]-Elicop[i][2])>0&&Elicop[i][0]==1)Caz=2;
		else
			if((Elicop[i][3]-Elicop[i][1])*(Elicop[i][4]-Elicop[i][2])<0&&Elicop[i][0]==-1)Caz=3;
		    else
				Caz=4;
	nr1=0;

    int J=max(Elicop[i][1],Elicop[i][3])-min(Elicop[i][1],Elicop[i][3])+1;
    int Lx1=min(Elicop[i][1],Elicop[i][3]);
    int Ly1=min(Elicop[i][2],Elicop[i][4]);
	int Ly2=max(Elicop[i][2],Elicop[i][4]);
    switch(Caz)
         {case 1:{
	               for(int j=1;j<=J;j++)
			          for(int l=1;l<=j;l++)nr1+=!(Teren[j+Lx1-1][l+Ly1-1]);
		           break;
			     }
		  case 2:{
	               for(int j=1;j<=J;j++)
			          for(int l=j;l<=Ly2-Ly1+1;l++)   nr1+=!(Teren[j+Lx1-1][l+Ly1-1]);
		           break;
	              }
	      case 3:{
			       for(int j=1;j<=J;j++)
			          for(int l=(int)abs(Elicop[i][1]-Elicop[i][3])+2-j;l<=Ly2-Ly1+1;l++) nr1+=!(Teren[j+Lx1-1][l+Ly1-1]);
		           break;
			     }
	      case 4:{
			       for(int j=1;j<=J;j++)
			          for(int l=1;l<=(int)abs(Elicop[i][1]-Elicop[i][3])+2-j;l++) nr1+=!(Teren[j+Lx1-1][l+Ly1-1]);
		           break;
			     }				 
	         }
	nre+=!nr1;
	if(nr1>(abs(Elicop[i][1]-Elicop[i][3])+1)*(abs(Elicop[i][1]-Elicop[i][3])+2)/4)
		E_Sol[++nr_umbra]=i;
}
fprintf(g,"%d\n%d ",nre,nr_umbra);
for(int i=1;i<=nr_umbra;i++)
	fprintf(g,"%d ",E_Sol[i]);
fclose(g);
return 0;
}
