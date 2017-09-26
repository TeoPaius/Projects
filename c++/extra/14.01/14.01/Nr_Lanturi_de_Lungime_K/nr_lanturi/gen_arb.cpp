// Paduri de multimi disjuncte
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
using namespace std;

ofstream fout("arb.in");

typedef vector<int> VI;

VI t, h;
int cnt;

void Union(int, int);
int Find(int);

int main()
{
	srand(time(NULL));
	int n = rand() % 100 + 1;

	t = VI(n + 1), h = VI(n + 1);
	for (int i = 1; i <= n; ++i)
		t[i] = i;
	int K = min(n / 2, rand() % 10);
	fout << n << ' ' << K << '\n';
	while ( true )
	{
		int x = rand() % n + 1, y = rand() % n + 1;

		int r1 = Find(x), r2 = Find(y);
		if ( r1 != r2 )
		{
			fout << x << ' ' << y << '\n';
			Union(r1, r2);
			cnt++;
			if ( cnt == n - 1 ) break;
		}
	}

    fout.close();
}


int Find(int x)
{
	if ( x == t[x] ) return x;
	return t[x] = Find(t[x]);
}

void Union(int x, int y)
{
	if ( h[x] > h[y] )
		t[y] = x;
	else
	{
		t[x] = y;
		h[y]++;
	}
}
