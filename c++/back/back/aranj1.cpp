/* GENERAREA Aranjamentelor (de n elemente luate cate p)
 * Sa se genereze toate posibilitatile de a acorda p premii intr-o clasa de n copii
 */

#include <fstream>
using namespace std;

ifstream is("aranj.in");
ofstream os("aranj.out");

int x[100];   // x[k] = i  ( premiul k se acorda copilului i);
bool s[100];  // s[i] = true (valoarea i a fost pusa deja in stiva)
int n, p;    // copii, premii
int nrsol;

void Aranj(int k);
void Write(int k);

int main()
{
	is >> n >> p;
	Aranj(1);
	os << nrsol << " solutii!";
	is.close();
	os.close();
}

void Aranj(int k)
{
	if ( k > p )
	{
		Write(k - 1);
		return;
	}
	for ( int i = 1; i <= n; ++i )
	{
		x[k] = i;
		if ( !s[i] )
		{
			s[i] = true;
			Aranj(k + 1);
			s[i] = false;
		}
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << x[i] << ' ';
	os << '\n';
}















