/* GENERAREA COMBINARILOR (de n elemente luate cate p)
 * (genearea submultimilor de cardinal p ale unei multimi de cardinal n)

    Sa se genereze toate posibilitatile de a alcatui o delegatie formata din p elevi,
    intr-o clasa cu n elevi
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
	is >> n >> p;
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
	for ( int i = x[k - 1]  + 1; i <= n - p + k; ++i )
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















