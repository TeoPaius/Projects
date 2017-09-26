#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#define NMax 500
#define LgMax 101
#define nfout "pod.out"
#define nfin "pod.in"
int n, uz[NMax], s[NMax], poz[NMax], test, lg;
typedef char Big[LgMax];
Big NrOk, Nr;
ofstream fpunct("punctaj.txt",ios::app);

void CitireIn();
void CitireOk(char *);
void eror(char *);
void EliminSpatii(Big);

void main(int nrarg, char *arg[])
{
  CitireIn();
  if (nrarg<2) eror("Nr testului trebuie specificat ca parametru\n");
  test=atoi(arg[1]);
  CitireOk(arg[1]);
  if (!fpunct) fpunct.open("punctaj.txt",ios::out);
  ifstream fout(nfout);
  if (!fout) eror ("Fisier de iesire inexistent");
  fout.getline(Nr, 100);
  EliminSpatii(Nr);
  if (strcmp(Nr, NrOk)) eror("Numar incorect");
  int x;
  while(fout>>x) poz[lg++]=x;
  if (poz[0]>3 || poz[0]<1 || s[poz[0]]) eror("Traversare incorecta");
  for (int i=1; i<lg; i++)
      {if (poz[i]<=poz[i-1] || poz[i]>n || s[poz[i]] || poz[i]-poz[i-1]>3) eror("Traversare incorecta");
       if ((uz[poz[i]]|| uz[poz[i-1]])&& poz[i-1]!=poz[i]-1) eror("Traversare incorecta");}
  if (poz[lg-1]<n-2 || uz[poz[lg-1]]&&poz[lg-1]!=n) eror("Traversare incorecta");
  cout<<"Corect! 10 puncte\n";
  fpunct<<10<<endl;
  fpunct.close();
}
void eror (char *s)
{
cout<<s<<' '<<"0 puncte\n";
fpunct<<0<<endl;
fpunct.close();
exit(0);
}
void CitireOk(char * s)
{
char nume[20];
strcpy(nume, s); strcat(nume,".out");
ifstream f(nume);
f.getline(NrOk,100);
EliminSpatii(NrOk);
f.close();
}
void CitireIn()
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
void EliminSpatii(Big n)
{
while (n[0]==' ') strcpy(n,n+1);
lg=strlen(n)-1;
while(lg>=0 && n[lg]==' ') n[lg--]=NULL;
}

