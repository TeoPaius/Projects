// de refacut
// Minim in intervalul [1..x]
// 1 x y -intreaba minim pe [1, y]
// 0 x y -SETEAZA a[x] la valoarea y 
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

#define DIM 1000

int a[DIM];
int n;
int aib[DIM];

void Update(int pos, int val)
{
	for ( int i = pos; i <= n; i += i & -i )
		aib[i] = min(aib[i], val);
}

int Query(int pos)
{
	int minim = 0x3f3f3f3f;
	for ( int i = pos; i > 0; i -= i & -i)
		minim = min(minim, aib[i]);
	return minim;
}

ifstream fin("aib.in");
ofstream fout("aib.out");

int main()
{
	fin >> n;
	for ( int i = 1; i <= n; ++i )
		aib[i] = 0x3f3f3f3f;
	for ( int i = 1; i <= n; ++i )
	{
		fin >> a[i];
		Update(i, a[i]);
	}

	
	int m;
	fin >> m;
	int op, x, y;
	for ( int i = 0; i < m; ++i )
	{
		fin >> op >> x >> y;
		if ( op == 0 ) Update(x, y);
		if ( op == 1 )
		{
			if ( x > 1 )
				fout << Query(y) - Query(x - 1) << '\n';
			else
				fout << Query(y) << '\n';
		}
	}
	fin.close();
	fout.close();
	return 0;
}

void Debug()
{
	for ( int i = 1; i <= n; ++i )
		fout << aib[i] << ' ';
	fout << '\n';
}
