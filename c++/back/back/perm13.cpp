/* GENERAREA PERMUTARILOR
 * Sa se generreze toate modurile posivbile de a aseza n copii pe n scaune
 */ 

#include <fstream>
using namespace std;

ifstream is("perm.in");
ofstream os("perm.out");

int x[100];   // x[k] = i (pe scaunnul k punem copilul i) 
bool s[100];  // s[i] = true (valoarea i a fost pusa deja in stiva)
int n;
int nrsol;

void Perm(int k);
void Write(int k);

int main()
{
	is >> n;
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
		os << x[i] << ' ';
	os << '\n';
}















