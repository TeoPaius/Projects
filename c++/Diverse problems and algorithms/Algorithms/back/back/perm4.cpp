/* GENERAREA PERMUTARILOR
 * Sa se toate permutarile unui sir numeric
 */ 

#include <fstream>
using namespace std;

ifstream is("perm1.in");
ofstream os("perm1.out");

int x[100];   // generam pozitii din sirul a;
int a[100];
bool s[100];  // s[i] = true (valoarea i a fost pusa deja in stiva)
int n;
int nrsol;

void Perm(int k);
void Write(int k);

int main()
{
	is >> n;
	for ( int i = 1; i <= n; ++i )
		is >> a[i];
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
		os << a[x[i]] << ' ';
	os << '\n';
}















