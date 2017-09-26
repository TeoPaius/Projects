/* GENERAREA PERMUTARILOR
 * Sa se generreze toate modurile posivbile de a aseza n copii pe n scaune
 */

#include <fstream>
#include <cstdlib>
using namespace std;

ifstream is("perm.in");
ofstream os("perm.out");

int x[100];   // x[k] = i (pe scaunnul k punem copilul i)
int n;
int nrsol;

void Perm(int k);
void Write(int k);
bool OK(int k);

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
	for ( int i = 1; i <= n; ++i )
	{
		x[k] = i;
		if ( OK(k) )
		{
			if ( k == n )
				Write(k);
			else
				Perm(k + 1);
		}
	}
}

void Write(int k)
{
	nrsol++;
	for ( int i = 1; i <= k; ++i )
		os << x[i] << ' ';
	os << '\n';
	if ( nrsol == 6 )
        exit(0);
}

bool OK(int k)
{
	for ( int i = 1; i < k; ++i )
		if ( x[i] == x[k] )
			return false;
	return true;
}















