
#include <fstream.h>
#include <stdlib.h>
#define DIM 300
#define IN   "pluto07.in"
#define OUT  "pluto.out"


int f[DIM][DIM];
int c[DIM][DIM];
int n, m;
int S, T;
int t[DIM];
int sel[DIM];
int di[DIM];
int de[DIM];
int flow;

void Citire();
void Build();
void Edmonds_Karp();
int FindPath();
void Augment();
void Flux();
void Afisare();

int q[DIM];
int p, u; 

int main()
{
    Citire();
    Build();
    Edmonds_Karp();
    Flux();
    return 0;
}

void Citire()
{
    int v1, v2, cap;
    ifstream fin(IN);
    fin >> n >> m;
    for ( int i = 1; i <= n; i++ )
        fin >> de[i];
    for ( int i = 1; i <= n; i++ )
        fin >> di[i];
    fin.close();
}

void Build()
{
    S = 0, T = 2*n + 1;
    for ( int i = 1; i <= n; i++ )
        c[S][i] = de[i];
    for ( int i = n + 1; i <= 2 * n; i++ )
        c[i][T] = di[i - n];
 
    for ( int i = 1; i <= n; i++ )
        for ( int j = n + 1; j <= 2 * n; j++ )
            if ( i + n != j) c[i][j] = 1;   // arc de la i la i
}

void Edmonds_Karp()
{
    while ( FindPath() )
        Augment();
}

int FindPath()
{
    memset ( q, 0, sizeof(q) );
    memset ( sel, 0, sizeof(sel));
    memset ( t, 0, sizeof(t) );  
    
    p = u = 1;
    q[1] = S;
    t[S] = 0;
    sel[S] = 1;
    while ( p <= u )
    {
        int i = q[p++];
        for ( int j = 1; j <= T; j++ )   // am 2*n + 1 noduri in graf
            if ( !sel[j] )
            {
                if ( c[i][j] > f[i][j] )
                {
                    sel[j] = 1;
                    t[j] = i;
                    q[++u] = j;
                    if ( j == T ) return 1;
                }    
                if ( f[j][i] )
                {
                    sel[j] = 1;
                    t[j] = -i;
                    q[++u] = j;
                    if ( j == T ) return 1;
                }    
            }    
            
       }       
    return 0;
}

void Augment()
{
    int i, j = T;
    while ( j != S )
    {
        i = abs(t[j]);
        if ( t[j] >= 0) f[i][j]++;
        else f[j][i]--;
        j = i;
    }    
    flow++;
}    
        
void Flux()
{
    ofstream fout(OUT);
 //   fout << flow << "\n";
 /*  for ( int i = 1; i <= n; i++ )
        fout <<  de[i] << " ";
        fout << "\n";
    for ( int i = 1; i <= n; i++ )
        fout << di[i] << " ";
    fout << "\n";
*/
/*
    for ( int i = 0; i <= 2*n + 1; i++ )
    {
        for ( int j = 0; j <= 2 * n + 1; j++ )
            fout << c[i][j] << " ";   // arc de la i la i
        fout << "\n";
    }    
    fout << "\n";
    for ( int i = 0; i <= 2 * n + 1; i++ )
    {
        for ( int j = 0; j <= 2 * n + 1; j++ )
            fout << f[i][j] << " ";   // arc de la i la i
        fout << "\n";
    }    
*/
    if ( flow != m ) fout << "NO\n";
    else 
    {
        fout << "YES\n";
       
        for ( int i = 1; i <= n; i++ )
            for ( int j = n + 1; j <= 2 * n; j++ )
                if ( f[i][j] && i != j - n) fout << i << " " << j - n << "\n";
    }    
    fout.close();
}



        
    
