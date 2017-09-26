// Sume in intervalul [x..y]
// 1 x y -intreaba suma pe [x, y]
// 0 x y -SETEAZA a[x] la y 
#include <fstream>
using namespace std;

#define DIM 1000

int a[DIM];
int n;
int aib[DIM];

// scad valoarea anterioara a lui a[pos] si adaug valoarea noua
void Update(int pos, int val, int old)
{
	for ( ;pos <= n; pos += pos & -pos )
		aib[pos] += val, aib[pos] -= old;
	a[pos] = val;
}

int Query(int pos)
{
	int s = 0;
	for ( ; pos > 0; pos-= pos & -pos)
		s += aib[pos];
	return s;
}

ifstream fin("aib.in");
ofstream fout("aib.out");

int main()
{
	fin >> n;
	for ( int i = 1; i <= n; ++i )
	{
		fin >> a[i];
		Update(i, a[i], 0);
	}	
	int m;
	fin >> m;
	int op, x, y;
	for ( int i = 0; i < m; ++i )
	{
		fin >> op >> x >> y;
		if ( op == 0 ) Update(x, y, a[x]);
		if ( op == 1 )
		{
		//	if ( x > 1 )
				fout << Query(y) - Query(x - 1) << '\n';
		//	else
		//		fout << Query(y) << '\n';
		}
	}
	fin.close();
	fout.close();
	return 0;
}
