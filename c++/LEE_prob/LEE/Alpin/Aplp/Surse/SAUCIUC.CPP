// Raluca Sauciuc
#include <stdio.h>

#define NMax	51
#define MAX		32001

int i,j,k,l,m,n,a[NMax][NMax];
char huge frecv[MAX],last[MAX];
char c[NMax][NMax];

void load(void)
{
	FILE *fp=fopen("harta.in","rt");
	fscanf(fp,"%d%d",&m,&n);
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) fscanf(fp,"%d",&a[i][j]);
	fclose(fp);
}

// a) un vector de frecvente pentru elementele care apar , apoi elementul
// cel mai frecvent e cautat din nou pt a vedea in ce zone e.
void frecvente(void)
{
	int max,ult;
	FILE *fp=fopen("harta1.out","wt");

	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if (last[a[i][j]]!=i) { frecv[a[i][j]]++; last[a[i][j]]=i; }
	for(max=0,i=0;i<MAX;i++) if (frecv[i]>frecv[max]) max=i;
	fprintf(fp,"%d\n",max);
	for(ult=0,i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if (a[i][j]==max)
				if (ult!=i) { fprintf(fp,"%d ",i); ult=i; }
	fclose(fp);
}

// PD ( c[i][j]=cea mai lunga "excursie" care poate porni din (i,j) respectand
// conditiile problemei ). Asemanator cu cel mai lung subsir cresc. O(N^4)
// (E posibil sa nu fi inteles exact ce vrea problema, deci ... ;) )
void drum(void)
{
	int max=0,si,sj;
	FILE *fp=fopen("harta2.out","wt");

	for(j=1;j<=n;j++) c[m][j]=1;
	for(i=m-1;i>=1;i--)
		for(j=1;j<=n;j++)
			{
				c[i][j]=1;
				for(k=i+1;k<=m;k++)
					for(l=1;l<=n;l++)
						if (a[i][j]<a[k][l])
							if (c[i][j]<c[k][l]+1) c[i][j]=c[k][l]+1;
				if (c[i][j]>max) { max=c[i][j]; si=i; sj=j; }
			}
	fprintf(fp,"%d %d\n",si,sj);
	for(i=si+1;i<=m;i++)
		for(j=1;j<=n;j++)
			if (a[si][sj]<a[i][j])
				if ((c[si][sj]==c[i][j]+1)&&(si<i))
					{ fprintf(fp,"%d %d\n",i,j); si=i; sj=j; }
	fclose(fp);
}

void main(void)
{
	load();
	frecvente();
	drum();
}