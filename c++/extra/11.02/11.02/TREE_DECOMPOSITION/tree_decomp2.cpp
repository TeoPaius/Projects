// Tree decomposition
// Suma lantului de la x la y = suma(x, LCA) + suma(LCA, y) - s[LCA]
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define DIM 1000 //noduri
ifstream fin("arb.in");
ofstream fout("arb.out");

typedef vector<int> VI;
typedef VI::iterator IT;

int arb[4*DIM];      // tine sume pentru sirul a
int a[2*DIM + 2], Poz[2*DIM + 2]; // Poz[x] - poz primei aparitii a lui x in sirul a
int pa, v; // pozitia in sirul a pe care se va scrie valoarea v
int cnt1;  // poz in sirul a
int A, B; // intervalul de  interogare pt sirul a (necesar pt arb de intervale)

int E[2*DIM + 2], PozE[2*DIM+1];  // PozE[x] - poz primei aparitii a nodului z in turul Euler
int niv[2*DIM + 2], cnt2;  // cnt2 - poz in turul Euler si in niv
int pmin[DIM][17];        // pmin[i][j] pozitia minimului in sirul niv, incepand de la poz i si de lungime 2^j  (RMQ)

bool s[DIM];
VI G[DIM], val;     
int n, m;

void Read();
void Update(int nod, int left, int right);
int Query(int nod, int left, int right);
void Df(int x, int nv);
void Preprocesare();

int main()
{
    Read();
    Df(1, 1);
    Preprocesare();
//	Debug();
  
    fin >> m;
	int op, x, y;
    for ( int i = 1; i <= m; ++i )
    {
        fin >> op >> x >> y; // x = 0 update, x = 1, query
        if ( op == 0 )
        {
            pa = x;   // pozitia de update     
            v = y;    // valoarea de update
            Update(1, 1, 1000);
        }    
        else
        {
			int lca, i = PozE[x], j = PozE[y];;
            
			if ( i > j )
			{
				int aux = i; i = j; j = aux;
			}
			
			int k = (int)floor(log(j - i)/log(2)); // log2(a) = ln(a)/ln(2)

			if (niv[pmin[i][k]] <= niv[pmin[j-(1 << k)+1][k]] )
				lca = E[pmin[i][k]];
			else
				lca = E[pmin[j-(1 << k)+1][k]];
			
			A = Poz[lca];    // pozitia in sirul a
			B = Poz[x];
			int suma1  = Query(1, 1, 1000);
			
			B = Poz[y];
			int suma2 = Query(1, 1, 1000);
		    fout << suma1 + suma2 - val[lca] << '\n';
        }    
    }
         
    fin.close();
    
    return 0;
}
    

void Df(int x, int nv)
{
    cnt1++;
    s[x] = true;
    a[cnt1] = val[x];
    Poz[x] = cnt1;
    // introducem valoarea v in arb de intervale
    v = a[cnt1]; pa = cnt1;
    Update(1, 1, 1000);
         
    cnt2++;
    E[cnt2] = x;
    PozE[x] = cnt2;
    niv[cnt2] = nv;

    for ( IT it = G[x].begin(); it != G[x].end(); ++it )
        if ( !s[*it] )
		{
			Df(*it, nv + 1);
			cnt2++;
			E[cnt2] = x; 
			niv[cnt2] = nv;
		}
		
    cnt1++;
    a[cnt1] = -val[x];
    v = a[cnt1]; pa = cnt1;
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
    if ( pa <= mij )
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

void Preprocesare()  // x, y pozitii
{
	n = 2 * n + 1;
	int k = (int)floor(log(n)/log(2));     // k == log2(n)
	for ( int i = 1; i <= n; i++ ) pmin[i][0] = i;   // indicii sirului niv se pun pe prima coloana
                                                 // pmin[i][0] = pozitia minimului pt sirul niv[]
	for ( int j = 1; j <= k; j++ )                   // in intervalul [i, i + 2^0 - 1] = i
		for ( int i = 1; i <= n; i++ )  // pe coloane !
		{
			pmin[i][j] = pmin[i][j-1];     // poz minimului in interv [i, i + 2^(j-1) -1]
			if (i + (1 << (j-1)) <= n && niv[pmin[i][j]] > niv[pmin[i+(1 << (j-1))][j-1]] )
				pmin[i][j] = pmin[i+(1 << (j-1))][j-1]; // pmin[i+(1<<(j-1))][j-1]]  e poz minimului pt sirul niv[] in inter-
		}                                               // valul [i+2^(j-1), i + 2^j -1]
}


void Read()
{
    fin >> n;
    val.resize(n + 1);
    
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
	
    cout << "Poz: ";
    for ( int i = 1; i <= n; ++i )
        fout << Poz[i] << ' ';
    cout << "\nvali " ;;
    
    for ( int i = 1; i <= pa; ++i )
        cout << a[i] << ' ';
    cout << "\nEul: ";
    
    for ( int i = 1; i <= pa; ++i )
        cout << E[i] << ' ';
    cout << "\nniv: ";
    for ( int i = 1; i <= pa; ++i )
        cout << niv[i] << ' '; 
  cin.get();
}    
