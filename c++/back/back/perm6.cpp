/* GENERAREA PERMUTARILOR
 * Sa se toate anagramele unui cuvant
 */ 

#include <fstream>
#include <string>
using namespace std;

ifstream is("perm2.in");
ofstream os("perm1.out");

int x[100];   // generam pozitii din sirul a;
string cuv;
bool s[100];  // s[i] = true (valoarea i a fost pusa deja in stiva)
int n;
int nrsol;

void Perm(int k);
void Write(int k);

int main()
{
	is >> cuv;
	n = cuv.length();
	Perm(1);
	os << nrsol << " solutii!";
	is.close();
	os.close();
}

void Perm(int k)
{
	if ( k > n )
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
			Perm(k + 1);
			s[i] = false;
		}
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << cuv[x[i] - 1] << ' ';
	os << '\n';
}















