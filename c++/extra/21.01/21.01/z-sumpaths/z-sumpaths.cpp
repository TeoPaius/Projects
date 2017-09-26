// Nr total de lanturi de suma M
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 50002;
const int MAXM = 102;
const int MOD = 321555123;

int N, M;
vector<pair<int, int > > V[SIZE];
bool S[SIZE];

vector<int> Dfs(int x)
{
	S[x] = true;
	
	vector<int> A(MAXM);
	for (vector<pair<int, int> >::iterator it = V[x].begin(); it != V[x].end(); ++it)
		if (!S[it->first]) 
		{
			vector<int> B = Dfs(it->first), C(MAXM);
			A[0] += B[0];
			if (A[0] >= MOD) A[0] -= MOD;
			
			if (it->second < M) A[0] += B[M - it->second];
			else if (it->second == M) ++A[0];
			if (A[0] >= MOD) A[0] -= MOD;
			
			for (int i = it->second + 1; i <= M; ++i)
				C[i] = B[i - it->second];
			C[it->second] = 1;
			for (int i = 1; i <= M - 1; ++i)
			{
				A[0] += 1LL * A[i] * C[M - i] % MOD;
				if (A[0] >= MOD) A[0] -= MOD;
				A[i] += C[i];
				if (A[i] >= MOD) A[i] -= MOD;
			}
		}
	return A;
}

int main()
{
	cin >> N >> M;
	for (int i = 1, nod1, nod2, costn; i < N; ++i)
	{
		cin >> nod1 >> nod2 >> costn;
		V[nod1].push_back(make_pair(nod2, costn));
		V[nod2].push_back(make_pair(nod1, costn));
	}
	
	vector<int> now = Dfs(1);
	cout << now[0];
}
