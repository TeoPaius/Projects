/*
 BS - PD

   Se foloseste un graf orientat complet, din care se elimina ulterior anumite
muchii. 
*/ 


#include <stdio.h>
#include <iostream.h>
#define infile "zmeu.in"
#define outfile "zmeu.out"
#define infinit 1000000

typedef struct coada {
       int info;
       coada* urm;
} NOD, *PNOD;

PNOD prim, ultim; // prim = inceputul cozii folosita de BFS()
                  // ultim = sfarsitul cozii folosita de BFS()

int n, p, k, timp[201], cap[201];
int a[201][201], min[201][501]; // a = matricea de adiacenta
    // min[i][j] = durata minima pentru a iesi din povestea i cu j capete

void Read();
void BFS();
void Write();
void Add(int k); // adauga la sfarsit in coada nodul k
void Delete(); // sterge din coada primul nod

int main()
{
 Read();
 BFS();
 Write();
 return 0;
}

void Read()
{
 FILE* fin = fopen(infile, "rt");
 int i = 0, j = 0, z = 0;
 fscanf(fin, "%d %d %d", &n, &p, &k);
 for ( i = 1; i <= p; i++ )       // initializez matricea de adiacenta
     for ( j = 1; j <= p; j++ )
         if ( i == j ) a[i][j] = 0;
         else          a[i][j] = 1;
 a[1][p] = a[p][1] = 0;
 for ( i = 1; i <= p; i++ )
     for ( j = 1; j <= n; j++ )
         min[i][j] = infinit;
 for ( i = 1; i <= p; i++ )
     a[i][1] = a[p][i] = 0;
 for ( i = 1; i <= p; i++ )
     fscanf(fin, "%d %d", timp + i, cap + i);
 for ( i = 1; i <= k; i++ )
 {
  fscanf(fin, "%d %d", &j, &z);
  a[j][z] = 0;
 }
 fclose(fin);
}

void BFS()
{
 int i = 0, x = 0, j = 0;
 int nr[201];            // nr[i] = arata de cate ori nodul i a fost introdus
                         //         in coada
 memset(nr, 0, sizeof(nr));
 Add(1);
 min[1][n-cap[1]] = timp[1];
 nr[1] = 1;
 while ( prim )
 {
  x = prim->info;
  for ( i = 1; i <= p; i++ )  // parcurg vecinii nodului x
      if ( a[x][i] )
         for ( j = 1; j <= n; j++ )
             if ( min[x][j] != infinit )
                if ( j - cap[i] > 0 && min[i][j-cap[i]] > min[x][j] + timp[i] )
                {
                 if ( !nr[i] ) // este suficient ca un nod sa fie introdus
                 {            // in coada o singura data
                  Add(i);
                  nr[i] = 1;
                 }
                 min[i][j-cap[i]] = min[x][j] + timp[i];
                }
  Delete();
 }
}

void Add(int k)
{
 if ( prim == 0 )
 {
  prim = new coada;
  prim->info = k;
  prim->urm = 0;
  ultim = prim;
 }
 else if ( ultim->info != k )
 {
  PNOD p = new coada;
  p->info = k;
  p->urm = 0;
  ultim->urm = p;
  ultim = p;
 }
}

void Delete()
{
 PNOD p = new coada;
 p = prim;
 prim = prim->urm;
 delete p;
}

void Write()
{
 FILE* fout = fopen(outfile, "wt");
 int i = 0, minim = infinit;
 for ( i = 1; i <= n; i++ )
        if ( minim > min[p][i] )minim = min[p][i];
 if ( minim != infinit )fprintf(fout, "%d\n", minim);
 else                   fprintf(fout, "%s\n", "-1");
 fclose(fout);
}


 
