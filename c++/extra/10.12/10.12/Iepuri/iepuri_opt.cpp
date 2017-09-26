// OK
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ofstream fout("iepuri.out");
#define Mod 30011

typedef vector<int> VI;
VI t;
vector<VI> G;
int n, K;   // K- nr max de morcovi
int root;

void Read();
VI Df(int); 

int main()
{
	Read();
	VI res = Df(root);

	fout << res[K] << '\n';
	fout.close();	
	return 0;
}

VI Df(int x)
{
	VI X(K + 1, 1);  // X[i] - nr moduri in care iepurele x poate avea exact i morcovi 
	VI S(K + 1);     // S[i] in cate moduri pot avea in x cel mult i morcovi
	
	for (const int&f : G[x])
	{
		VI F = Df(f);
		for (int i = 1; i <= K; ++i )  // pt fiec nr posibil de morcovi in x
		{	
			int P = F[K] - F[i];    // in cate moduri pot avea in fiu cel putin i + 1 morcovi = X[i + 1] + X[i + 2] + ... + X[K]
			if (P < 0)              // nu mai e nevoie de un vector auxiliar
				P += Mod;
			X[i] = (X[i] * P) % Mod;
		}
	}	
	
	for (int i = 1; i <= K; ++i)
		S[i] = (S[i - 1] + X[i]) % Mod;
	return S;
}

void Read()
{
	ifstream fin("iepuri9.in");
	fin >> n >> K;
	t.resize(n + 1); G.resize(n + 1);
	int a, b;
	for ( int i = 1; i < n; ++i )
	{
		fin >> a >> b;
		G[a].push_back(b);
		t[b] = a;
	}
	for (int i = 1; i <= n; ++i )
		if ( t[i] == 0 )
		{
			root = i;
			break;
		}
}

