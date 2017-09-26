#include <fstream.h>
#define NMaxVf 102
#define Infinit -1
#define nin "loc.in"
#define nout "loc.out"

typedef int Graf[NMaxVf][NMaxVf];
Graf G;
long  d[NMaxVf], nrd[NMaxVf], nrmax;
int n, p;

void Initializare();
void Dijkstra();
void Determina_maxim();
void Afisare();

void main()
{Initializare();
 Dijkstra();
 Determina_maxim();
 Afisare();}

void Initializare()
{int m, x, y, c;
 ifstream fin(nin);
 fin>>n; fin>>m;
 cout<<"...."<<endl;
 for (x=0; x<=n; x++)
     for (y=0; y<=n; y++) G[x][y]=Infinit;
 for (int i=0; i<m; i++)
     {fin>>x>>y>>c;
      if (G[x][y]!=Infinit) cout <<"se repeta muchia "<<x<<' '<<y<<endl;
         else G[x][y]=G[y][x]=c;}
fin.close();
d[0]=0; nrd[0]=1;
for (i=1; i<=n; i++) {d[i]=G[0][i]; nrd[i]=1;}
}

void Dijkstra()
{int m[NMaxVf];
 m[0]=1;
 for (int i=1; i<=n; i++) m[i]=0;
 int nrvf=1, vfmin;
 long min;
 while (nrvf<=n)
      {min=Infinit;
       for (i=1; i<=n; i++)
           if (!m[i] && d[i]!=Infinit && (d[i]<min || min==Infinit))
              {min=d[i];vfmin=i;}
       m[vfmin]=1; nrvf++;
       if (min!=Infinit)
       for (i=1; i<=n; i++)
           if (!m[i] && G[vfmin][i]!=Infinit)
              if (d[i]==Infinit || d[i]>min+G[vfmin][i])
                 {d[i]=min+G[vfmin][i];
                  nrd[i]=nrd[vfmin];}
                 else
                 if (d[i]==min+G[vfmin][i])
                    nrd[i]+=nrd[vfmin];
      }
}

void Determina_maxim()
{ nrmax=-1; p=0;
  for (int i=1; i<=n; i++)
      if (nrd[i]>nrmax)
         {nrmax=nrd[i]; p=i;}
}

void Afisare()
{ofstream fout(nout);
 fout<<p<<endl;
 fout<<nrmax<<endl;
 fout<<d[p]<<endl;
 fout.close(); }

