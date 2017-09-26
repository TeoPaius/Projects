// Tree decomposition 
// se calculeaza suma pe lantul de la x la y, unde x e stramosul lui y

#include <fstream>
#include <vector>
using namespace std;

ifstream fin("arb.in");
ofstream fout("arb.out");

typedef vector<int> VI;
typedef VI::iterator IT;

int arb[4*1000];
VI  a, Poz, val;
bool s[1000];
VI G[1000];
int poz, v; // pozitia in sirul a pe care se va scrie valoarea v
int p, n, m;
int A, B; // intervalul de pozitii de interogare
int suma; // suma pe interval

void Update(int nod, int left, int right);
int Query(int nod, int left, int right);

void Df(int x, int nv)
{
    p++;
    s[x] = true;
    a[p] = val[x];
    Poz[x] = p;
    
    v = a[p]; poz = p;
    Update(1, 1, 1000);
    for ( IT it = G[x].begin(); it != G[x].end(); ++it )
        if ( !s[*it] )
		{
			Df(*it, nv + 1);
		}
    p++;
    a[p] = -val[x]; 
    v = a[p]; poz = p;
    Update(1, 1, 1000);
}    

void Update(int nod, int left, int right)
{
    if ( left == right )
    {
        arb[nod] = v;
        return;
    }    
    int mij = (left + right) >> 1;
    if ( poz <= mij )
        Update(2*nod, left, mij);
    else
        Update(2*nod + 1, mij + 1, right);
    arb[nod] = arb[2*nod] + arb[2*nod + 1];
}    

int Query(int nod, int left, int right)
{
    if ( A <= left and right <= B )
		return arb[nod];
   
    
    int mij = (left + right) >> 1;
    int s1 = 0, s2 = 0;
    if ( A <= mij )
        s1 = Query(2*nod, left, mij);
    if ( B > mij ) 
        s2 = Query(2*nod + 1, mij + 1, right);
    return s1 + s2;
}    

void Read()
{
    fin >> n;
    val = VI(n + 1);
    a = Poz =  VI(2 * n + 1);
    
    for ( int i = 1; i <= n; ++i )
        fin >> val[i];
    
    int x, y;
    for ( int i = 1; i < n; ++i )
    {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
   
}    

void Debug()
{
    fout << '\n';
    for ( int i = 1; i <= n; ++i )
        fout << firstPos[i] << ' ';
    fout << '\n';
    
    for ( int i = 1; i <= p; ++i )
        fout << a[i] << ' ';
    fout << '\n';
}    

int main()
{
    Read();
    Df(1, 1);
  //  Debug();
    fin >> m;
	int x, y, z;
    for ( int i = 1; i <= m; ++i )
    {
        fin >> x >> y >> z; // x = 0 update, x = 1, query
        if ( x == 0 )
        {
            poz = y;
            v = z;
            Update(1, 1, 1000);
        }    
        else
        {
            A = Poz[y]; // prima pozitie a lui y
            B = Poz[z];
			if ( A > B )
			{
				int aux = A; A = B; B = aux;
			}
     
            fout << Query(1, 1, 1000) << '\n';
        }    
    }    
    fin.close();
    
    return 0;
}
    
