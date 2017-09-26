//prof.Gina Balacea
#include<cstdio>
#include<cmath>
FILE *f,*g;
int x,n,p=1;
int nragri=0,nt=0;
int main()
{f=fopen("porumb.in","r");
 g=fopen("porumb.out","w");
  
 fscanf(f,"%d%d",&n,&x);
 if(x%2==1) {nt=1;
             while(p<=n) {p*=2;nragri++;
                         }
            }
 else
     while(p<=n) {p*=2;nragri++;
                  if(x%p==(p/2)) nt=nragri;
				 }

 
 
 fprintf(g,"%d\n%d\n%d\n%d",(n+1)/2,nragri,nt,p/2);
 
 fclose(f);
 fclose(g);
 return 0;
}
