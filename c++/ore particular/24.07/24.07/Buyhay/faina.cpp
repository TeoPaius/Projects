#include <fstream>
using namespace std;
#define INF 99999999
#define MAXS 60000
#define MAXN 1001

ifstream fin("buyhay.in");
ofstream fout("buyhay.out");

int g, p, c[MAXS + 1], G, N;

int main()
{
	fin >> N >> G;
	int i, j;
	
	for ( i = 0; i <= MAXS; ++i )
		c[i] = INF;
	
	c[0] = 0;
	
	for ( i = 1; i <= N; ++i )
	{
		fin >> g >> p;
		for ( j = 0; j < MAXS; ++j )
			if ( c[j] != INF )
				if ( c[j+g] > c[j] + p )
					c[j+g] = c[j] + p;
	}
	int min = INF;
	for ( i = G; i <= MAXS ;++i )
		if ( c[i] < min )
			min = c[i];
	
	fout << min << '\n';
	
	fin.close();
	fout.close();
	
	return 0;
}
