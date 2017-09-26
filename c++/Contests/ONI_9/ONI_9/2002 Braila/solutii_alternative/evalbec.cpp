
// Evaluare problema Becuri, clasa a IX-a, ONI 2002, Braila

#include <stdio.h>
#include <string.h>

#define DIM 10240
#define SIZE 100

FILE *f=NULL;
long nok=0,nout=0;
char linec[DIM+1]={0},linel[DIM+1]={0};
char fs[15]={0};
char a[SIZE+1][SIZE+1]={0},b[SIZE+1][SIZE+1]={0};
int i=0,j=0,m=0,n=0,x=0;
int main(int argc, char *argv[])
{
 if(argc<2) { printf("Specificati numarul testului pentru care doriti evaluarea\
 (evalbec <nr.test>)."); return 0; }
 strcpy(fs,argv[1]);
 strcat(fs,".Ok");
 f=fopen(fs,"rt");
 if(!f)
 { printf("Fisierul de iesire (%s) ce contine solutia corecta nu a fost gasit in directorul curent.",fs); return 0; }
 while(1)
 {
  if(fscanf(f,"%d",&x)==EOF) break;
  else if(x>0) ++nok;
  else if(x<0) { nok=-1; break; }
 }
 fclose(f);
 f=fopen("BECURI.OUT","rt");
 if(!f)
 { printf("Fisierul de iesire (BECURI.OUT) ce trebuie evaluat nu a fost gasit in directorul curent."); return 0; }
 fgets(linec,DIM,f);
 fgets(linel,DIM,f);
 fclose(f);
 f=fopen("BECURI.IN","rt");
 if(!f)
 {
  memset(fs,0,sizeof(fs));
  strcpy(fs,argv[1]); strcat(fs,".IN");
  f=fopen(fs,"rt");
  if(!f) { printf("Fisierul de intrare (BECURI.IN sau %s) nu a fost gasit in directorul curent.",fs); return 0; }
 }
 fscanf(f,"%d %d",&m,&n);
 for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
    fscanf(f,"%d",&(b[i][j]));
 fclose(f);
 nout=0,j=0;
 sscanf(linec,"%d",&x);
 if(x<0)
   if(nok<0) goto label;
   else { printf("Exista solutie, dar fisierul de iesire evaluat nu a gasit-o. 0 puncte"); return 0; }
 while(!(linec[j]>='0' && linec[j]<='9') && linec[j]) ++j;
 while(1)
 {
   if(sscanf(linec+j,"%d",&x)==EOF) break;
   else if(x>0) ++nout;
   else break;
   if(x<1 || x>n) { printf("Fisierul de iesire evaluat contine indici de coloane in afara domeniului. 0 puncte"); return 0; }
   for(i=1;i<=m;i++) a[i][x]=!a[i][x];
   while(linec[j]!=' ' && linec[j]) ++j;
   while(!(linec[j]>='0' && linec[j]<='9') && linec[j]) ++j;
 }
 j=0;
 while(!(linel[j]>='0' && linel[j]<='9') && linel[j]) ++j;
 while(1)
 {
   if(sscanf(linel+j,"%d",&x)==EOF) break;
   else if(x)
   {
     if(x<1 || x>m)
     { printf("Fisierul de iesire evaluat contine indici de linii in afara domeniului. 0 puncte"); return 0; }
     else ++nout;
     for(i=1;i<=n;i++) a[x][i]=!a[x][i];
   }
   else break;
   while(linel[j]!=' ' && linel[j]) ++j;
   while(!(linel[j]>='0' && linel[j]<='9') && linel[j]) ++j;
 }
 for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
    if(a[i][j]!=b[i][j]) { printf("Fisierul de iesire evaluat nu contine solutie corecta. 0 puncte."); return 0; }
 if(nout>nok) { printf("Fisierul de iesire contine un numar prea mare de linii si coloane actionate."); return 0; }
 else if(nout<nok) printf("Felicitari!!! Fisierul de iesire evaluat contine un numar mai mic de linii si coloane actionate decat solutia oficiala.\n");
label:
 printf("Solutie CORECTA!!! Felicitari!!! Congratulations!!! Bravoo!!! OK!!!");
 return 0;
}
