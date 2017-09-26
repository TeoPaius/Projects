#include <fstream.h>
#define NMax 1000
#define nfout "9.o"
#define nfin "9.in"
int n, uz[NMax], s[NMax], poz[NMax];
long Nr[NMax];

void Afisare();
void Rezolva();
void Citire();

void main()
{
  Citire();
  Rezolva();
  Afisare();
}

void Afisare()
{
long Total=0;
int d[NMax], final, lg;
if (!s[n]) {Total+=Nr[n]; final=n;}
if (Nr[n-1]!=-1 && !uz[n-1]) {Total+=Nr[n-1]; final=n-1;}
if (Nr[n-2]!=-1 && !uz[n-2]) {Total+=Nr[n-2]; final=n-2;}
if (!Total) Total=-1;
ofstream fout(nfout);
fout<<Total<<endl;
if (Total!=-1)
   {d[0]=final; lg=1;
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
Nr[1]=1;  poz[1]=0;
if (s[2]) Nr[2]=-1;
   else {Nr[2]=2; poz[2]=0;}
if (s[3]) Nr[3]=-1;
   else
   if (s[2]) {Nr[3]=2; poz[3]=0;} // Nr[3] = Nr[1] + 1
      else {Nr[3]=4; poz[3]=0;}
for (int i=4; i<=n; i++)
    if (s[i]) Nr[i]=-1;  // nu pot ajunge
       else
       if (uz[i]) { Nr[i]=Nr[i-1]; poz[i]=i-1;}
          else
          {Nr[i]=0;
           if (Nr[i-1]!=-1) {Nr[i]=Nr[i-1];poz[i]=i-1;}
           if (Nr[i-2]!=-1 && !uz[i-2]) {Nr[i]+=Nr[i-2];poz[i]=i-2;}
           if (Nr[i-3]!=-1 && !uz[i-3]) {Nr[i]+=Nr[i-3];poz[i]=i-3;}
           if (!Nr[i]) Nr[i]=-1;}
}