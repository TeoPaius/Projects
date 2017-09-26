#include <fstream>
using namespace std;
#define DIM 1000

ifstream fin("aib.in");
ofstream fout("aib.out");

int aib[DIM]; // aib
int n;

int Query(int poz) // suma [1...poz]
{
	int s = 0;
	for ( int i = poz; i; i -= i & -i)
		s += aib[i];
	return s;
}

void Update(int poz, int v)
{
	for ( int i = poz; i <= n; i += i & -i )
		aib[i] += v;
}

int main()
{
	int v, m;
	fin >> n >> m;       // m - nr de intrebari 1 - update, 0 suma
	for ( int i = 1; i <= n; ++i )
	{
		fin >> v;  // valorile din sirul original
		Update(i, v);
	}
	int c, p1, p2;
	for ( int i = 1; i <= m; ++i )
	{
		fin >> op;
		if ( op )
		{
			fin >> p1 >> v;
			Update(p1, v);
		}
		else
		{
			fin >> p1 >> p2;
			fout << Query(p2) - Query(p1 - 1) << '\n';
		}
	}

	fin.close();
	fout.close();
	return 0;
}
