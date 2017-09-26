#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ofstream fout("iepuri.out");
//#define cin fin
//#define cout fout
#define MOD 30011

typedef vector<int> VI;
VI t, sons;

int n, K;   // K- nr max de morcovi
int root;

void Read();
VI Df(int); 

int main()
{
	Read();
	VI a = Df(root);

	cout << a[K] << '\n';
	fout.close();	
	return 0;
}

VI Df(int x)
{
	VI X(K + 1, 1);  // X[i] - nr moduri in care iepurele x poate avea exact i morcuvi 
	VI S(K + 1);   // S[i] in cate moduri pot avea in x cel mult i morcovi
	
	if ( !sons[x] )
	{
		for (int i = 1; i <= K; ++i)
			S[i] = (S[i - 1] + X[i]) % MOD;
		return S;
	}
	
	for ( int f = 1; f <= n; ++f )
		if ( t[f] == x )
		{
			VI F = Df(f);
			
			for (int i = 1; i <= K; ++i )  // pt fiec nr posibil de morcovi in x
			{	
				int P = F[K] - F[i];    // in cate moduri pot avea in fiu cel putin i + 1 morcovi = X[i + 1] + X[i + 2] + ... + X[K]
				if (P < 0)
					P += MOD;
				X[i] = (X[i] * P) % MOD;
			}
		}	
	
	for (int i = 1; i <= K; ++i)
		S[i] = (S[i - 1] + X[i]) % MOD;
	return S;
}

void Read()
{
	ifstream fin("iepuri.in");
	cin >> n >> K;
	t.resize(n + 1); sons.resize(n + 1);
	int a, b;
	for ( int i = 1; i < n; ++i )
	{
		cin >> a >> b;
		t[b] = a;
		sons[a]++;
		
	}
	for (int i = 1; i <= n; ++i )
		if ( t[i] == 0 )
		{
			root = i;
			break;
		}
}

