#include <fstream.h>
#define NMax 1001
#define nfout "9.b"
#define nfin "9.in"
int n, uz[NMax], s[NMax], p[NMax], sol[NMax], lgsol;
long NrSol;

void Afisare();
void Gen(int);
void Citire();

void main()
{
  Citire();
  p[0]=1;
  Gen(1);
  if (!s[2]) {p[0]=2; Gen(1);}
  if (!s[3]) {p[0]=3; Gen(1);}
  Afisare();
}

void Afisare()
{
ofstream fout(nfout);
if (!NrSol) fout<<-1<<endl;
   else
   {fout<<NrSol<<endl;
    for (int i=0; i<lgsol; i++)
        fout<<sol[i]<<' ';
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


void GasitSol(int k)
{
NrSol++;
if (NrSol==1)
   {lgsol=k;
    for (int i=0; i<lgsol; i++) sol[i]=p[i];}
}
void Gen(int k)
{
if (p[k-1]==n) GasitSol(k);
    else
    if (p[k-1]==n-1)
       {if (!uz[n-1]) GasitSol(k);
        if (!s[n]) {p[k]=n; Gen(k+1);}
       }
       else
       if (p[k-1]==n-2)
          {
          if (!uz[n-2]) GasitSol(k); //sar direct
          if (!s[n-1]) {p[k]=n-1; Gen(k+1);}
          if (!s[n] && !uz[n] && !uz[n-2]) {p[k]=n; Gen(k+1);}
          }
       else
       {//mai sar
       if (!s[p[k-1]+1])
          {
          p[k]=p[k-1]+1;
          Gen(k+1);
          }
       if (!s[p[k-1]+2] && !uz[p[k-1]+2] &&!uz[p[k-1]])
          {
          p[k]=p[k-1]+2;
          Gen(k+1);
          }
       if (!s[p[k-1]+3] && !uz[p[k-1]+3] &&!uz[p[k-1]])
          {
          p[k]=p[k-1]+3;
          Gen(k+1);
          }
       }
}




