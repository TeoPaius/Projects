
// Evaluare problema Discuri, clasa a IX-a, ONI 2002, Braila

#include <stdio.h>
#include <string.h>

FILE *f=NULL,*g=NULL;
int i=0,k=0,kf=0,c=0,cf=0;
char fs[15]={0};
int main(int argc, char *argv[])
{
 if(argc<2) { printf("Specificati numarul testului pentru care doriti evaluarea\
 (evaldisc <nr.test>)."); return 0; }
 strcpy(fs,argv[1]);
 strcat(fs,".OUT");
 f=fopen("DISCURI.OUT","rt");
 if(!f)
 { printf("Fisierul de iesire (DISCURI.OUT) ce trebuie evaluat nu a fost gasit in directorul curent."); return 0; }
 if(!g)
 { printf("Fisierul de iesire (%s) ce contine solutia corecta nu a fost gasit in directorul curent.",fs); return 0; }
 g=fopen(fs,"rt");
 fscanf(f,"%d",&kf);
 fscanf(g,"%d",&k);
 if(kf!=k) { printf("Numar incorect de cercuri dispensabile."); return 0; }
 for(;i<k;i++)
 {
  fscanf(f,"%d",&cf);
  fscanf(g,"%d",&c);
  if(c!=cf)
    { printf("Solutia evaluata contine cel putin un cerc care nu este dispensabil."); return 0; }
 }
 fclose(f);
 fclose(g);
 printf("Solutie CORECTA!!! Felicitari!!! Congratulations!!! Bravoo!!! OK!!!");
 return 0;
}
