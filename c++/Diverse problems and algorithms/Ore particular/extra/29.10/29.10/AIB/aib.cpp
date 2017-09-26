#include <fstream>
using namespace std;
#define DIM 1000

ifstream fin("aib.in");
ofstream fout("aib.out");

int a[DIM];
int n;

int Query(int poz)
{
	int s = 0;
	for ( int i = poz; i; i -= i & -i)
		s += a[i];
	return s;
}

void Update(int poz, int v)
{
	for ( int i = poz; i <= n; i += i & -i )
		a[i] += v;
}

int main()
{
	int v, m;
	fin >> n >> m;       // m - nr de intrebari 1 - update, 0 query
	for ( int i = 1; i <= n; ++i )
	{
		fin >> v;
		Update(i, v);
	}
	int c, p1, p2;
	for ( int i = 1; i <= m; ++i )
	{
		fin >> c;
		if ( c )
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
