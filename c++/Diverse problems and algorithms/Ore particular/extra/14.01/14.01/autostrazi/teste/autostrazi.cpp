// Constantin Galatan
// Complexitate: O(N*K*S*S)

#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

ifstream fin("autostrazi.in");
ofstream fout("autostrazi.out");
#define MOD 30011

typedef vector<int> VI;
VI r;          
vector<VI> G;
int N, K;
int S;

vector<int> Df(int x, int father)
{
	vector<int> X(S + 1);
	int tmp(0), son(0);
	
	X[0] = 1;
	for (int pos = 0; pos < (int)G[x].size(); ++pos )
	{
		son = G[x][pos];
		if ( son == father ) continue;

		vector<int> F = Df(son, x);
		vector<int> A(S + 1);
		for ( int i = 0; i <= K; ++i )
			for ( int k = 0; k + r[i] <= S; ++k)
				for ( int j = 0; k + r[i] + j <= S; ++j)
				{
						tmp = A[max(j, k + r[i])];
						tmp += (X[j] * F[k]) % MOD;
						A[max(j, k + r[i])] = tmp % MOD;
					}
		X = A;
	}
	return X;
}

int main()
{
	fin >> N >> S >> K;
	G.resize(N + 1); r.resize(K + 1);
	for ( int i = 1; i <= K; ++i )
		fin >> r[i];
	int x, y;
	for (int i = 0; i < N - 1; ++i )
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	fin.close();
	vector<int> v = Df(1, 0);
	int sol = 0;
	for ( int i = 0; i <= S; ++i)
	{
		sol += v[i];
		sol %= MOD;
	}

	fout << sol << '\n';
	fout.close();
	return 0;
}



