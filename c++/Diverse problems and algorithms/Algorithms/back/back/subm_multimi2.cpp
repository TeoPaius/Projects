/* GENERAREA tuturor submultimilor unei multimi
 */

#include <fstream>
using namespace std;

ifstream is("comb.in");
ofstream os("comb.out");

int x[100];
int n, p;
int nrsol;

void Subm(int k);
void Write(int k);

int main()
{
	is >> n;
	Subm(1);
	os << nrsol << " solutii!";
	is.close();
	os.close();
}

void Subm(int k)
{
	for ( int i = x[k - 1]  + 1; i <= n; ++i )
	{
		x[k] = i;
		Write(k);
        Subm(k + 1);
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << x[i] << ' ';
	os << '\n';
}















