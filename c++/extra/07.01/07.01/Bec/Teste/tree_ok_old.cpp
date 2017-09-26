// OK
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ofstream fout("tree.out");
#define INF 99999

using VI = vector<int>;

int n, P;
VI t, nr, sons;
vector<VI> a; 

void Read();
void DF(int x);

int main()
{
	Read();
	if ( P == n )
	{
		cout << 0 << '\n';
		fout.close();
		return 0;
	}

	DF(1);

	int minim = INF;
	for (int i = 1; i <= n; ++i )
		if ( a[i][P] < minim )
			minim = a[i][P];
	cout << minim << '\n';
	
	fout.close();
	return 0;
}

void DF(int x)
{
	nr[x]++;
	a[x][1] = sons[x]; 
	if ( x != 1 ) 
		a[x][1]++; 
	for (int f = 1; f <= n; ++f )
		if ( t[f] == x )
		{	
			DF(f);
			nr[x] += nr[f];
			VI A(a[x]); 
			
			for ( int j = 1; j <= nr[f]; ++j ) 
				for ( int i = 1; i + j  <= nr[x]; i++ ) 
				{
					if ( a[x][i] == INF ) continue;
					if ( a[f][j] == INF ) continue;
					if ( A[i + j] > a[x][i] + a[f][j] - 2  ) 
						A[i + j] = a[x][i] + a[f][j] - 2;				
				}
			a[x] = A;	
		}
}

void Read()
{
	ifstream fin("tree.in");
	int son, father;
	cin >> n >> P;
	a.resize(n + 1);
	nr.resize(n + 1);
	t.resize(n + 1);
	sons.resize(n + 1);
	for ( int i = 1; i < n; ++i )
	{
		cin >> father >> son;
		t[son] = father;
		sons[father]++;
		a[i].resize(n + 1, INF);
	}
	
	a[n].resize(n + 1, INF);
	
	fin.close();
}
	


