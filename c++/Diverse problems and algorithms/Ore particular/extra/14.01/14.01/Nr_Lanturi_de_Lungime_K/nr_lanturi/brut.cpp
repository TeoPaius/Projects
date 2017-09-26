// Sa se det nr de lanturi de lungime K intr-un arbore (cost 1 pe muchii).
// Fac un Floyd-Warshall si apoi numar lanturile de lung K
// OK
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("arb.in");
ofstream fout("arb.out");
const int Inf = 0x3f3f3f3f;

template <typename T>
void Print(T t)
{
	for ( typename T::iterator it = t.begin(); it != t.end(); ++it)
		fout << *it << ' ';
	fout << '\n';
}

typedef vector<int> VI;
typedef vector<VI> VVI;

vector<bool> s;
VVI a;     // matricea costurilor drumurilor
int n, K, res;

void Read();
void FW(); // ret nr de lanturi care au capatul de sus in x
void Solve();
int main()
{
	Read();
	FW();
	Solve();
	fout << res;
    fout.close();
}

void Read()
{
	fin >> n >> K;
	a = vector<vector<int>>(n + 1, vector<int>(n + 1, Inf));
	for ( int i = 0; i <= n; ++i)
		a[i][i] = 0;
	int x, y;
	for (int i = 0; i < n - 1; ++i)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	fin.close();
}

void FW()
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j )
				if ( i != j && a[i][k] + a[k][j] < a[i][j] )
					a[i][j] = a[i][k] + a[k][j];
}

void Solve()
{
	for (int i = 1; i < n; ++i )
		for (int j = i + 1; j <= n; ++j)
			if ( a[i][j] == K )
				res++;
}
