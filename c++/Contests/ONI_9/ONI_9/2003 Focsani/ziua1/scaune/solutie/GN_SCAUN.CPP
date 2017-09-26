#include<stdio.h>
#include<stdlib.h>
#define MaxPoz 201

typedef int vector[MaxPoz];

const char *In="scaun.in";

vector x;

void main()
{ FILE *Fin;
  int i, j, aux, ok, n, ns;
  randomize();
  Fin=fopen(In, "w");
  printf("nr total de scaune = "); scanf("%d",&ns);
  printf("nr de copii de asezat ="); scanf("%d",&n);
  fprintf(Fin,"%d %d\n",ns, n);
  aux=random(ns)+1;
  x[1]=aux; fprintf(Fin,"%d\n",aux);
  for(i=2;i<=n;i++)
    { do { ok=1;
	   aux=random(ns)+1;
	   for(j=1;j<i;j++)
	     if(aux==x[j]){ ok=0; break; }
	 }while(!ok);
      x[i]=aux; fprintf(Fin,"%d\n", aux);
    }
  for(i=0;i<ns;i++) x[i]=0;
  printf("nr de scaune ce se elibereaza ="); scanf("%d",&n);
  aux=random(ns)+1;
  x[1]=aux; fprintf(Fin,"%d\n",aux);
  for(i=2;i<=n;i++)
    { do { ok=1;
	   aux=random(ns)+1;
	   for(j=1;j<i;j++)
	     if(aux==x[j]){ ok=0; break; }
	 }while(!ok);
      x[i]=aux; fprintf(Fin,"%d\n", aux);
    }
   fclose(Fin);
}
