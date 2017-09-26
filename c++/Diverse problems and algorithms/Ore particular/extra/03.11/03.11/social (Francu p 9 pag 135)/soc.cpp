//problema culegere catalin francu
#include <stdio.h>

#define Nmax 101
#define max(x, y) ((x > y) ? x : y)

int N;
int p[Nmax], q[Nmax];
int r;

typedef struct Nod {
    int vf;
    Nod *urm;
} *PNOD;

PNOD L[Nmax];

FILE *fin, *fout;

void Read();
void Df(int nod);
void Write();

int main()
{
    Read();
    Df(r);
    Write();
    
    return 0;
}

void Add(int i, int val)
{
    PNOD pt = new Nod;
    pt->vf = val;
    pt->urm = L[i];
    L[i] = pt;
}
    
void Read()
{
    int v;   
    fin = fopen("soc.in", "rt");
    fscanf(fin, "%d", &N);
    for (int i = 1; i<= N; i++)
    {
        fscanf(fin, "%d", &v);
        if (v == 0) 
            r = i;
        else 
            Add(v, i);
    }
    for (int i = 1; i <= N; fscanf(fin, "%d", &p[i++]));
    for (int i = 1; i <= N; i++) printf("%d ", p[i]);
    fgetc(stdin);
    fclose(fin);
}

void Df(int nod)
{
    printf("%d ", nod);
    fgetc(stdin); // cin.get();
    for (PNOD pt = L[nod]; pt ; pt = pt->urm)
    {
        Df(pt->vf);
        p[nod] += q[pt->vf];
        q[nod] += max(q[pt->vf], p[pt->vf]);
    }
}

void Write()
{
    fout = fopen("soc.out", "wt");
    fprintf(fout, "%d\n", p[r]);
    for ( int i = 1; i <= N; i++ )
        fprintf(fout, "%d ", p[i]);
    
    fclose(fout);
}        
