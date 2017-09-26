/* culori O(n*L) - L = lungimea rezultatului  prof. Eugen Mot */  
#include <stdio.h>
#include <string.h>
#define C 1500
int w[2][C], b[2][C], r[2][C], g[2][C], y[2][C]; /* de la white, blue, red etc. */
void copy(int a[], int b[])
{int i;
 for(i=0;i<C;i++) b[i]=a[i];
}
void sum(int a[], int b[], int c[]) 
{int i,t=0,r;
 c[0]=(a[0]>=b[0]?a[0]:b[0]);
 for(i=1;i<=c[0];i++)
 {r=a[i]+b[i]+t; c[i]=(r>9?r-10:r); t=r>9;}
 if(t) {c[0]++; c[c[0]]=1;}
}
int main()
{FILE *fi,*fo;
 int i,j,k,n; 
 fi=fopen("culori.in","r");
 fscanf(fi,"%d",&n);
 fclose(fi);
 w[1][0]=b[1][0]=r[1][0]=g[1][0]=y[1][0]=1;
 w[1][1]=b[1][1]=r[1][1]=g[1][1]=y[1][1]=1;
  for(i=2;i<=n;i++)
    {j=i&1; k=1-j;
     copy(b[k],w[j]); 
     sum(w[k],r[k],b[j]); 
     sum(b[k],g[k],r[j]); 
     sum(r[k],y[k],g[j]); 
     copy(g[k],y[j]);}
 j=n&1; k=1-j;
 sum(w[j],b[j],w[k]); 
 sum(w[k],r[j],b[k]); 
 sum(b[k],g[j],r[k]); 
 sum(r[k],y[j],g[k]); 
 fo=fopen("culori.out","w");
 for(i=g[k][0];i>0;i--) fprintf(fo,"%d",g[k][i]);
 fclose(fo);
 return 0;
}
