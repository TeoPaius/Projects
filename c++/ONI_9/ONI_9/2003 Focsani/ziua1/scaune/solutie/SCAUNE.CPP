#include<stdio.h>
#define MaxPoz 202

const char *InputFile ="scaune.in";
const char *OutputFile="scaune.out";

typedef int vector[MaxPoz];

/*
  PozIn[i] = n, cu semnificatia scaunul n este in lista initiala pe pozitia i;
  PozLoc[i]= 0, daca in dreptul pozitiei i nu este nici un scaun
	     n, daca in dreptul pozitiei i este scaunul n,
		pentru a ocupa locul i
  Loc[i] = 0, daca pe pozitia i nu a fost pus nici un scaun
	   n, numarul scaunului pus pe pozitia i
  Muta [] = vector auxiliar in care se vor roti scaunele dupa asezarea unuia
	    dintre ele, vecto ce va fi copiat in PozLoc.
*/

vector PozIn, PozLoc, Loc, Muta;

int n, poza, locp, liber, nrmut;
int gasitloc, faraloc;

FILE *fin, *fout;

void init()
{ int i;
  for(i=0;i<MaxPoz;i++)
    PozIn[i]=PozLoc[i]=Loc[i]=0;
}

void prelucrare()
{ int n, poza, locp, liber, nrmut, ns;
  int gasitloc, faraloc;
  int i, ok;
  fin = fopen(InputFile,"r");
  fout= fopen(OutputFile, "w");
  fscanf(fin,"%d %d",&ns, &n);
  for(i=1;i<=n;i++)
    { fscanf(fin,"%d",&poza);
      PozLoc[poza]=i;
      PozIn[i]=poza;
    }
  faraloc=0;
  while(!feof(fin)&&!faraloc)
   { fscanf(fin,"%d",&liber);
     if(!feof(fin))
     {
     gasitloc=0;
     i=liber;
     while(i>=1&&!gasitloc)
       { if(PozLoc[i]) { locp=PozLoc[i];
			 nrmut=liber-i;
			 gasitloc=1;
			}
	 else i--;
       }
     if(!gasitloc) { i=ns;
		     while((i>=liber+1)&&!gasitloc)
		       { if(PozLoc[i]) { locp=PozLoc[i];
					 nrmut=ns-i+liber;
					 gasitloc=1;
				       }
			 else i--;
		       }
		    }
     if(!gasitloc) faraloc=1;
     else { Loc[locp]=liber;
	    PozLoc[i]=0;
	    for(i=1;i<=ns;i++)
	       if(i+nrmut<=ns) Muta[i+nrmut]=PozLoc[i];
	       else Muta[i+nrmut-ns]=PozLoc[i];
	    for(i=1;i<=ns;i++)
	       PozLoc[i]=Muta[i];
	  }
     }
   }

  ok=1;
  for(i=1;i<=n;i++)
    if(Loc[i]) { fprintf(fout,"%d %d \n",PozIn[i],Loc[i]); ok=0; }
    else { fprintf(fout,"%d %d\n",PozIn[i],0); ok=0; }
  if(ok&&faraloc) fprintf(fout,"%d",0);
  fclose(fin);
  fclose(fout);
}

void main()
{ init();
  prelucrare();
}