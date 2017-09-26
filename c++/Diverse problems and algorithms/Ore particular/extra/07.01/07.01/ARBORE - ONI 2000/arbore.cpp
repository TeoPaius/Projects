#include <cstdlib>
#include <fstream>
#include <utility>

using namespace std;

#define fiu first
#define val second

ofstream fout("arbore.out");

void Dfs(int x);
void Print(int x, int s);

int n, k;
int t[101], v[101];
pair<int, int> a[101][1001];

int main()
{
	ifstream fin("ARBORE.I2");

	fin >> n >> k;
	fin >> v[1];
	for (int i = 2; i <= n; ++i)
		fin >> t[i] >> v[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			a[i][j].fiu = a[i][j].val = -1;
	Dfs(1);

	fout << -1;

	fout.close();
	fin.close();
}

void Dfs(int x)
{
	a[x][v[x]].val = 0; 
	if (v[x] == k)
	{
		Print(x, k);
		fout.close();
		exit(0);
	}
	for (int f = 1; f <= n; ++f)
		if (t[f] == x)
		{
			Dfs(f);
			for (int i = 0; i <= k; ++i) // pentru fiecare suma a fiului
				if (a[f][i].val != -1)   // daca suma a fost obtinuta
					for (int j = k; j >= i; --j)
						if (a[x][j].val == -1 && a[x][j - i].val != -1 && a[x][j - i].fiu != f)
						{
							a[x][j].fiu = f;
							a[x][j].val = i;
							if (j == k)
							{
								Print(x, k);
								fout.close();
								exit(0);
							}
						}
		}
}

void Print(int x, int s)
{
	fout << x << '\n';

	int aux = s;
	s -= v[x];

	while (s > 0 && a[x][aux].val > 0)
	{
		Print(a[x][aux].fiu, a[x][aux].val);
		aux -= a[x][aux].val;
	}
}
