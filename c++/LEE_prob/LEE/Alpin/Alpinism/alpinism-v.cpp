#include <stdio.h>

#define MAX 201
#define iv (i + di[d])
#define jv (j + dj[d])

const int di[] = { -1, 0, 1, 0 }, dj[] = { 0, 1, 0, -1 };

int a[MAX][MAX], c[MAX][MAX], ok = 0;
int n;

struct Alpin {
    int v, l, c;
} b[MAX*MAX], maxim;

FILE *fout = fopen("alpin.out", "wt" );

void Read()
{
    FILE *fin = fopen("alpin.in", "rt" );
    fscanf(fin, "%d", &n );
    for ( int i = 1; i <= n*n; i++ )
    {
        fscanf(fin, "%d ", &b[i].v );
        b[i].l = (i-1)/n + 1;
        b[i].c = (i-1)%n + 1;
        a[b[i].l][b[i].c] = b[i].v;
    }
    fclose(fin);
}

void Sort(int st, int dr)
{
    int pivot = b[st].v;
    int i = st - 1, j = dr + 1;
    do
    {
        do { i++; } while ( b[i].v < pivot );
        do { j--; } while ( b[j].v > pivot );
        if ( i <= j )
        {
            Alpin aux = b[i];
            b[i] = b[j];
            b[j] = aux;
        }    
    } while ( i <= j );
    if ( i < dr ) Sort(i, dr);
    if ( st < j ) Sort(st, j);
}

void Alpinist()
{
    int i, j, k;
    maxim.v = 0;
    for ( k = 1; k <= n*n; k++ )
    {
        i = b[k].l; j = b[k].c;
        for ( int d = 0; d <= 3; d++ )
        {
            if ( a[i][j] > a[iv][jv] && (iv <= n && jv <= n && iv > 0 && jv > 0) )
                if ( c[i][j] < c[iv][jv] + 1 ) c[i][j] = c[iv][jv] + 1;
            if ( maxim.v < c[i][j] ) { maxim.v = c[i][j], maxim.l = i, maxim.c = j; }
        }
    }
}

void Rec(int i, int j)
{
    if ( !c[i][j] ) 
    {
        fprintf(fout, "%d\n%d %d %d %d", maxim.v, i, j, maxim.l, maxim.c );
        ok = 1;
        return;
    }
    else
    {
        for ( int d = 0; d < 4; d++ )
        {
            if ( iv <= n && jv <= n && iv > 0 && jv > 0 )
                if (c[i][j] == c[iv][jv] + 1 && (!ok) ) Rec(iv, jv);
        }
    }
}

void Write()
{
    int i, j;
    /*for ( i = 1; i <= n*n; i++ )
        fprintf(fout, "%d %d%d\n", b[i].v, b[i].l, b[i].c );
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
            fprintf(fout, "%d ", c[i][j] );
        fprintf(fout,"\n" );
    }*/
    Rec(maxim.l, maxim.c);   
    fclose(fout);
}

int main()
{
    Read();
    Sort(1, n*n);
    Alpinist();
    Write();
    
    return 0;
}
