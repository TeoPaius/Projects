// ok
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#define MOD 30011

typedef vector<int> VI;
vector<VI> G;
VI fa;
ofstream fout("iepuri.out");

int n, K, root;
void Read();
VI DF(int nod);

int main()
{
	Read();
	
	VI res = DF(root);
	
//	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
	int s = 0;
	for ( int i = 1; i <= K; ++i )
		s = (s + res[i]) % MOD;
	fout << s << '\n';
	
	fout.close();
}

VI DF(int x)
{
	VI rx(K + 1, 1);
	
	for (const int& son : G[x])
	{
		VI rs = DF(son);
		VI tmp(K + 1);
		for ( int i = 1; i <= K; ++i )   // citi are nod
			for ( int j = i + 1; j <= K; ++j) // cati are son
			{
				tmp[i] +=  (rs[j] * rx[i]) % MOD;
				tmp[i] %= MOD;
			}
		rx = tmp;
	}
	return rx;
}


void Read()
{
	ifstream fin("iepuri7.in");
	fin >> n >> K;
	G.resize(n + 1); fa.resize(n + 1);
	int father, son;
	for ( int i = 1; i < n; ++i )
	{
		fin >> father >> son;
		fa[son] = father;
		G[father].push_back(son);
	}
	
	for ( int i = 1; i <= n; ++i )
		if (fa[i] == 0 )
		{
			root = i;
			break;
		}
	
	fin.close();
}
