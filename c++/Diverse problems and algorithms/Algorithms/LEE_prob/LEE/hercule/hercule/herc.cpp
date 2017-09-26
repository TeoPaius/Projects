#define DIM 201
#define INF 32000
#include <fstream>
using namespace std;

const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
 
typedef struct nod {
    int l, c;
    nod* urm;
} NOD, *PNOD;

PNOD prim, ultim;

struct tata {
    int l, c;
} t[DIM][DIM];

int m, n, izero, jzero, iunu, junu;
int a[DIM][DIM];
int timp[DIM][DIM];
int d;

ofstream fout("hercule.out");
    
void Add(int lin, int col);
void Erase();
int  OK( int, int);
void Lee();
void Read();
void Show( int, int );
void Show();

int main()
{
    Read();
    Lee();
    Show();
    fout.close();
    return 0;
}
    
void Show()
{
    if( a[iunu][junu] < INF ) 
    {
        fout << a[iunu][junu] << '\n';
        Show( iunu, junu );
    }    
    else fout << "-1\n";
}    


void Read()
{
    ifstream fin("hercule.in");
    fin >> m >> n;
    for( int i =1; i <= m; i++ )
        for( int j = 1; j <= n; j++ )
        {
            fin >> timp[i][j];
            a[i][j] = INF;
        } 
     fin >> izero >> jzero >> iunu >> junu;
     fin.close();
 }
        
void Show( int i, int j )
{
    if(!t[i][j].l && !t[i][j].c ) return;
    Show( t[i][j].l, t[i][j].c);
    fout << i << " " << j << '\n';
}

void Add(int lin, int col)
{
    if ( !prim )
    {
        prim = new NOD;
        prim->l = lin;
        prim->c = col;
        prim->urm = 0;
        ultim = prim;
    }
    else
    {        
        PNOD p = new NOD;
        p->l = lin;
        p->c = col;
        p->urm = 0;
        ultim->urm = p;
        ultim = p;
    }    
}
    
void Erase()
{
    PNOD p = prim;
    prim = prim->urm;
    delete p;
    if ( !prim ) ultim = 0;
}

#define iv (i + di[d])
#define jv (j + dj[d])

void Lee()
{
    a[izero][jzero] = 0;
    Add(izero, jzero);
    for ( PNOD p = prim; p; Erase(), p = prim )
    {
        int i = p->l;
        int j = p->c;
        for ( d = 0; d < 8; d++ )
            if ( OK(i, j) && a[i][j] + 1 < a[iv][jv] ) 
            {
                a[iv][jv] = a[i][j] + 1;
                Add(iv, jv);
                t[iv][jv].l = i;
                t[iv][jv].c = j;
                if ( iv == iunu && jv == junu ) return;
            }
    }    
}    

int OK(int i, int j)
{
    return ( iv >= 1 && iv <= m && jv >= 1 && jv <= n && a[i][j] + 1 < timp[iv][jv] );
}                           
                
            

    



    
    
