#include <fstream>
#include <vector>
using namespace std;

ifstream is("iepuri.in");
ofstream os("iepuri.out");

#define Mod 30011

int n, k;
int t[101];
vector<vector<int> > s;

int sol;
vector<vector<int> > G;
int aux1, aux2;
int source;

void Df(int node);

int main()
{
	is >> n >> k;
	G.resize(n+1);
	s = vector<vector<int> >(n + 1, vector<int>(k + 1, 1));
	
	for(int i = 1; i <= n-1; ++i)
	{
		is >> aux1 >> aux2;
		t[aux2] = aux1;
		G[aux1].push_back(aux2);
	}

	
	for(int i = 1; i <= n; ++i)
		if(t[i] == 0)
			source = i;
	Df(source);
	
	for(int i = 1; i <= k; i++)
		sol = (sol + s[source][i]) % Mod;
	
	os << sol;
	
	is.close();
	os.close();
	return 0;
}

void Df(int node)
{
	for( const auto& fiu : G[node])
	{
		Df(fiu);
		//temp.assign(k + 1, 0);
		vector<int> temp(k + 1);
		for(int i = 1; i <= k; ++i)
			for(int j = i + 1; j <= k; ++j)
			{
				temp[i] += (s[node][i] * s[fiu][j]) % Mod; 
				if(temp[i] > Mod)
					temp[i] -= Mod;
			}
		s[node] = temp;
	}
}
