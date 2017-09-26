// Constantin Galatan
// Complexitate: O(N*K*S*S)

#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("autostrazi.in");
ofstream fout("autostrazi.out");
#define Mod 30011

using VI = vector<int>;
VI r;          
vector<VI> G;
int N, K, S;

VI Df(int x, int father);

int main()
{
	cin >> N >> S >> K;
	G.resize(N + 1); r.resize(K + 1);
	for ( int i = 1; i <= K; ++i )
		cin >> r[i];
	int x, y;
	for (int i = 0; i < N - 1; ++i )
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	fin.close();
	
	VI v = Df(1, 0);
	int sol = 0;
	for ( int i = 0; i <= S; ++i)
	{
		sol += v[i];
		sol %= Mod;
	}

	cout << sol << '\n';
	fout.close();
	return 0;
}


VI Df(int x, int father)
{
	VI X(S + 1);
	
	X[0] = 1;
	for (const int& son : G[x])
	{
		if ( son == father ) continue;

		VI F = Df(son, x);
		
		VI A(S + 1); // auxiliar
		
		for ( int i = 0; i <= K; ++i )
			for ( int k = 0; k + r[i] <= S; ++k)
				for ( int j = 0; k + r[i] + j <= S; ++j)
					if ( j >= k + r[i] )
					{
						A[j] += (X[j] * F[k]) % Mod;
						A[j] %= Mod;
					}
					else
					{
						A[k + r[i]] += (X[j] * F[k]) % Mod;
						A[k + r[i]] %= Mod;
					}
		X = A;
	}
	return X;
}


