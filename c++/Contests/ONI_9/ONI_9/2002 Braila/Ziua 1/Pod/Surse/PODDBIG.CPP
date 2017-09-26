#include <fstream.h>
#include <string.h>
#define NMax 500
#define LgMax 101
#define nfout "9.out"
#define nfin "9.in"
int n, uz[NMax], s[NMax], poz[NMax];
typedef char Big[LgMax];
Big Nr[NMax];

void Afisare();
void Rezolva();
void Citire();
void Sum (Big &, Big &);
void main()
{
  Citire();
  Rezolva();
  Afisare();
}

void Afisare()
{
Big Total="0";
int d[NMax], final, lg;
if (!s[n]) {Sum(Total,Nr[n]); final=n;}
if (strcmp(Nr[n-1],"-1") && !uz[n-1]) {Sum(Total,Nr[n-1]); final=n-1;}
if (strcmp(Nr[n-2],"-1") && !uz[n-2]) {Sum(Total,Nr[n-2]); final=n-2;}
ofstream fout(nfout);
if (strcmp(Total,"0"))
   fout<<-1<<endl;
   else
   {fout<<strrev(Total)<<endl;
   d[0]=final; lg=1;
    while (poz[final]!=0) {d[lg++]=poz[final]; final=poz[final];}
    for (final=lg-1; final>=0; final--)
        fout<<d[final]<<' ';
    fout<<endl;
    }
fout.close();
}

void Citire()
{
  ifstream f(nfin);
  int x, k, h;
  f>>n>>k;
  for(int i=0;i<k;i++) {f>>x; s[x]=1;}
  //s[x]=1 daca scandura x lipseste si 0 altfel
  f>>h;
  for(i=0;i<h;i++) {f>>x; uz[x]=1;}
  //uz[x]=1 daca scandura x este deteriorata si 0 altfel
  f.close();
}

void Rezolva()
{
strcpy(Nr[1],"1");  poz[1]=0;
if (s[2]) strcpy(Nr[2],"-1");
   else {strcpy(Nr[2],"2"); poz[2]=0;}
if (s[3]) strcpy(Nr[3],"-1");
   else
   if (s[2]) {strcpy(Nr[3],"2"); poz[3]=0;}
      else {strcpy(Nr[3],"4"); poz[3]=0;}
for (int i=4; i<=n; i++)
    if (s[i]) strcpy(Nr[i],"-1");
       else
       if (uz[i]) { strcpy(Nr[i],Nr[i-1]); poz[i]=i-1;}
          else
          {strcpy(Nr[i],"0");
           if (strcmp(Nr[i-1],"-1")) {strcpy(Nr[i],Nr[i-1]);poz[i]=i-1;}
           if (strcmp(Nr[i-2],"-1") && !uz[i-2]) {Sum(Nr[i],Nr[i-2]);poz[i]=i-2;}
           if (strcmp(Nr[i-3],"-1") && !uz[i-3]) {Sum(Nr[i],Nr[i-3]);poz[i]=i-3;}
           if (!strcmp(Nr[i],"0")) strcpy(Nr[i],"-1");}
}

void Sum (Big & A, Big & B) // aduna
{
//adun pe B la A
int t=0, cifra;
for (int i=0; A[i] && B[i]; i++)
    {cifra = (A[i]-'0'+B[i]-'0'+t);
     A[i]=cifra%10+'0'; // codul ASCII al carterului
     t=cifra/10;}
for (; A[i]; i++)
    {cifra = (A[i]-'0'+t);
     A[i]=cifra%10+'0';
     t=cifra/10;}
for (; B[i]; i++)
    {cifra = (B[i]-'0'+t);
     A[i]=cifra%10+'0';
     t=cifra/10;}
A[i]=NULL;
if (t) {A[i]=t+'0'; A[i+1]=NULL;}
}