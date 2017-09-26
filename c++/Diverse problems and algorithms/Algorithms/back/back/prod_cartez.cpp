/* GENERAREA Produsului cartezian a n multimi
   A - multime de cardinal n.
   Generam A x B x ....
   Sa se genereze toate modalitatile de a comanda un meniu
 */

#include <fstream>
using namespace std;

ifstream is("cartez.in");
ofstream os("cartez.out");

int x[100];
int card[100]; // cardinalele multimilor
int n;     // nr de multimi
int nrsol;

void Cartez(int k);
void Write(int k);

int main()
{
	is >> n;
	for ( int i = 1; i <= n; ++i )
        is >> card[i];
	Cartez(1);
	os << nrsol << " solutii!";
	is.close();
	os.close();
}

void Cartez(int k)
{
	if ( k > n )
	{
		Write(k - 1);
		return;
	}
	for ( int i = 1; i <= card[k]; ++i )
	{
		x[k] = i;
        Cartez(k + 1);
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << x[i] << ' ';
	os << '\n';
}















