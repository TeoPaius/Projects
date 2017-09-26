/*
	Complexitate O(n x n x k)
	70 puncte
*/

#include<fstream>
#define inFile "blis.in"
#define outFile "blis.out"
#define dim 1005

using namespace std;

char s[dim];
int t[dim], n, k, valm;
int a[dim][dim], d[dim];

void Citire()
{
	ifstream fin(inFile);
	fin >> k;
	fin >> s;
	fin.close();
	
	for (n = 0; s[n]; n++) 
		t[n + 1] = s[n] - '0';
}

void Calcul()
{
	int i, j, x, p;
	
	// prima cerinta
	// determin valoarea maxima de cel mult k biti
	if (k >= n) // iau toti bitii
	{
		valm = 0;
		for (i = 1; i <= n; i++)
			valm |= (t[i] << (n - i));
	}
	else
	{
		// iau primii k biti
		x = 0;
		p = 0;
		for (i = 1; i <= k; i++)
		{
			x |= (t[i] << (k - i));
			p = (p << 1) + 1;
		}
		p >>= 1;
		valm = x;
		// iau pe rand urmatorii biti de la k+1 la n
		for (i = k + 1; i <= n; i++)
		{
			x = x & p;
			x = (x << 1) + t[i];
			if (valm < x) valm = x;
		}
	}
	
	// a doua cerinta
	a[0][1] = 100001;
	d[0] = 1;
	a[1][1] = t[1];
	d[1] = 1;
	
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= d[i - 1]; j++)
			a[i][j] = a[i - 1][j];
		d[i] = d[i - 1];
		a[i][d[i] + 1] = 100001;
		x = 0;
		for (j = i; (j >= 1) && (j >= i - k + 1); j--)
		{
			x = x | (t[j] << (i - j));
			for (p = 1; p <= d[j-1] && x > a[j-1][p]; p++)
				;
			if (p <= d[j-1])
			{
				if (x < a[i][p])
					a[i][p] = x;
			}
			else
			{
				if (p > d[i])
				{
					d[i] = p;
					a[i][p] = x;
				}
				else if (x < a[i][p]) a[i][p] = x;
			}
		}
	}

	ofstream fout(outFile);
	fout << valm << "\n" << d[n] << "\n";
	fout.close();
}

int main()
{
	Citire();
	Calcul();
	
	return 0;
}
