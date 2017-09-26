#include <fstream.h>
#include <iostream.h>
#include <conio.h>

#define INF 50001

typedef struct Nod{
    int v, k;
    Nod *urm;
} NOD,*PNOD;    

int K, N, M;
int t[51][51];
int w[51][51];
int tmin[51][1001];
int prieten[51];
int Tmin=INF;
int Kmin;

void Citeste();
int Gasit(int);
void CautBin();
void Afis();

int main()
{
    Citeste();
    CautBin();    
    Afis();
    return 0;    
}    

void Citeste()
{
    ifstream fin("lanterna.in");
    fin >> N >> K;
    int i, x, y, j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            t[i][j] = w[i][j] = INF;   // cele 2 tipuri de costuri pe muchii
    for(i = 1; i <= N;i++)
        fin >> prieten[i];
        
    fin >> M;
    for(i = 1; i <= M; i++)
    {
        fin >> x >> y >> t[x][y] >> w[x][y];
        t[y][x] = t[x][y];
        w[y][x] = w[x][y];
    }    
    fin.close();
}

void CautBin()   // log K
{
    int hi, lo, med;
    hi = K; lo = 1;
    Tmin = Gasit(K);
    Kmin = K;
    while ( lo <= hi)
    {
        med = (hi + lo) >> 1;   // (hi + lo ) / 2;
//      cout << lo << " " << med << " " << hi <<"\n";
        if ( Gasit(med) == Tmin)
        {
            hi = med - 1;
            Kmin = med;
        }    
        else lo = med + 1;
//      cin.get();
    }    
}    

int Gasit(int watt)
{
//    cout << "w = "<<watt<<'\n';
    int i, j, wc;
    PNOD p = new NOD;
    PNOD q;
    p->v =1;
    p->k = 0;
    p->urm = 0;
    PNOD u = p;
    for(i = 1; i <= N; i++)
        for(j = 0; j <= watt; j++)
            tmin[i][j] = INF;   // timpul minim ca sa ajung in nopdul i cu j watti consumati din baterie
            
    tmin[1][0] = 0;
    while ( p )     // 
    {
        i = p->v;
        wc = p->k;
//      cout << i << " " << wc << '\n';
        for (j = 1; j <= N; j++)      
            if (w[i][j] <= watt - wc )
            {
                if (prieten[j] && tmin[j][0] > tmin[i][wc] + t[i][j])
                {
                    tmin[j][0]=tmin[i][wc]+t[i][j];
                    q = new NOD;
                    q->v = j;
                    q->k = 0;
                    q->urm = 0;
                    u->urm = q;
                    u = q;
                }    
                if(!prieten[j] && tmin[j][wc+w[i][j]] > tmin[i][wc] + t[i][j])
                {
                    tmin[j][wc+w[i][j]] = tmin[i][wc] + t[i][j];
                    q = new NOD;
                    q->v = j;
                    q->k = wc+w[i][j];
                    q->urm = 0;
                    u->urm = q;
                    u = q;
                }
            }    
        q = p;
        p = p->urm;
        delete q;
    }
    
    int min = INF;
    for( i = 0; i <= watt;i++)
        if (tmin[N][i] < min)
            min = tmin[N][i];
    return min;
}    

void Afis()
{
    ofstream fout("lanterna.out");
    fout << Tmin << " " << Kmin <<'\n';
    fout.close();
}    
