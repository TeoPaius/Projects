/* Produsul Cartezian a n multimi
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream is("prod_cartez.in");
ofstream os("prod_cartez.out");

int n;       // nr de multimi
int x[50];   // x[k] = i din multimea k se alege elem i
int card[50];// c[k] - card multimii k
int nrsol;

void ProdCartez(int k);
void Write(int);
void Read();

int main()
{
    Read();
    ProdCartez(1);
    os << nrsol << " solutii !!";
    is.close();
    os.close();
}

void ProdCartez(int k)
{
    if ( k > n )
    {
        Write(k - 1);
        return;
    }

    for (int i = 1; i <= card[k]; ++i)
    {
        x[k] = i;
        ProdCartez(k + 1);
    }
}

void Write(int k)
{
    nrsol++;
    for (int i = 1; i <= k; ++i)
        os << x[i] << ' ';
    os << '\n';
}

void Read()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        is >> card[i];
}


