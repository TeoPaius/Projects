#include <fstream>
using namespace std;
#define DIM 1000

ifstream fin("aib2d.in");
ofstream fout("aib2d.out");

int a[DIM][DIM];
int n;

int Query(int p1, int p2)
{
	int s = 0;
	for ( int i = p1; i; i -= i & -i)
		for ( int j = p2; j; j -= j & -j )
		s += a[i][j];
	return s;
}

void Update(int p1, int p2, int v)
{
	for ( int i = p1; i <= n; i += i & -i )
		for (int j = p2; j <= n; j += j & -j )
			a[i][j] += v;
}

int main()
{
	int v, m;
	fin >> n >> m;       // m - nr de intrebari 1 - update, 0 query
	for ( int i = 1; i <= n; ++i )
		for (int j = 1; j <= n; ++j )
		{
			fin >> v;
			Update(i, j, v);
		}
	int c, i, j;
	for ( int k = 1; k <= m; ++k )
	{
		fin >> c;
		if ( c )
		{
			fin >> i >> j >> v;
			Update(i, j, v);
		}
		else
		{
			fin >> i >> j;
			fout << Query(i, j) << '\n';
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}
