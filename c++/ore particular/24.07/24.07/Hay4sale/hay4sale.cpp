#include <fstream>
using namespace std;

ifstream fin("hay4sale.11.in");
ofstream fout("hay4sale.out");

int C, H;
int v[50001];
bool a[50001];

int main()
{
	fin >> C >> H;
	
	int i, j;
	for (i = 1; i <= H; i++)
		fin >> v[i];
		
	a[0] = true;
	
	for (i = 1; i <= H; ++i)
		for (j = C - v[i]; j >= 0; --j)	
			if (a[j])
			a[j + v[i]] = true;
				
	for (i = C; i >= 0; --i)
		if (a[i])
		{
			fout << i << '\n';
			break;
		}
	fin.close();
	fout.close();
	return 0;
}
