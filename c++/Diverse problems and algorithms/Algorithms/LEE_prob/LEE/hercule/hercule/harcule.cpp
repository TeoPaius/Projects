#include <fstream>
#include <iostream>
#include <iomanip>
#define INFINIT 200
using namespace std;

const int di[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dj[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int a[201][201], t[201][201];
int ip, jp, is, js;
int n, m, pas = 0, iv, jv;
void Lee();
void Write(int, int );
int OK(int, int);
ofstream fout("hercule.out");
int main()
{
    ifstream fin("hercule.in");
    fin >> m >> n;
    int i, j;
    for ( i = 1; i <= m; i++ )
        for ( j = 1; j <= n; j++ )
            fin >> t[i][j];
    fin >> ip >> jp >> is >> js;
    fin.close();
    
    for (  i = 1; i <= m; i++ )
        for ( j = 1; j <= n; j++ )
            a[i][j] = INFINIT;
    a[ip][jp] = 0;
   
    
    Lee();
 /*
 for ( i = 1; i <= m; i++ )  
    {
        for ( j = 1; j <= n; j++ )
            fout << setw(4) <<a[i][j];
        fout << endl;
    }    
  */ 
    if ( a[is][js] < INFINIT ) 
    {
        fout << a[is][js] << endl;
        Write(is, js);
    }
    else fout << -1;    
    fout.close();
    return 0;
}

void Lee()  // O(k*m*n)
{
    int modif, i, j;
    do
    {
        modif = 0;
        for ( i = 1; i <= m; i++ )
            for ( j = 1; j <= n; j++ )
                if ( a[i][j] == pas ) 
                    for ( int d = 0; d < 8; d++ )
                    {
                        iv = i + di[d];
                        jv = j + dj[d];
                        if ( OK(iv, jv) )
                        {
                            a[iv][jv] = pas+1;
                            modif = 1;
                            if ( iv == is && jv == js )
                               return;
                        }             
                    }
        pas++;      
    } while(modif);                
}

int OK(int i, int j)
{
    if ( i < 1 || i > m || j < 1 || j > n )
        return 0;
    if ( a[iv][jv] <= pas )
        return 0;
    if ( t[iv][jv] <= pas+1 )
        return 0;    
    return 1;
}

void Write(int i, int j)
{
//    cout << i << " " << j << "\n";
//    cin.get();
    if ( i == ip && j == jp )
        return;
    for ( int d = 0; d < 8; d++ )
    {
        int iv = i + di[d];
        int jv = j + dj[d];
            
//        cout << "vecini " << iv << " " << jv << "\n";
//
 //       cin.get();

        if ( iv >= 1 &&  iv <= m && jv > 1 && jv < n && a[iv][jv] == a[i][j] - 1 )
        {
            Write ( iv, jv ); 
            fout << i << " " << j << " \n";
            break;   
        }  
        
    }          
    
} 


















