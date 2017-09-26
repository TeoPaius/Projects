/* GENERAREA tuturor submultimilor unei multimi
 */

#include <fstream>
using namespace std;

ifstream is("comb.in");
ofstream os("comb.out");

int x[100];
int n, p;
int nrsol;

void Comb(int k);
void Write(int k);

int main()
{
	is >> n;
	for( p = 1; p <= n; ++p)
        Comb(1);
	os << nrsol << " solutii!";
	is.close();
	os.close();
}

void Comb(int k)
{
	if ( k > p )
	{
		Write(k - 1);
		return;
	}
	for ( int i = x[k - 1]  + 1; i <= n; ++i )
	{
		x[k] = i;
        Comb(k + 1);
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << x[i] << ' ';
	os << '\n';
}















