#include <fstream>
using namespace std;

ifstream fin("hay4sale.11.in");
ofstream fout("hay4sale.out");

int C, H;
int v;
bool a[50001];

int main()
{
	fin >> C >> H;
	
	int i, j;
	
		
	a[0] = true;
	
	for (i = 1; i <= H; ++i)
	{
		fin >> v;
		for (j = C - v; j >= 0; --j)	
			if (a[j])
			{
				a[j + v] = true;
				if (j + v == C)
				{
					fout << C << '\n';
					return 0;
				}
			}
	}
				
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
