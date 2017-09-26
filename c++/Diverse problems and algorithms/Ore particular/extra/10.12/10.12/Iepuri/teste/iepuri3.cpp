#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ifstream is("iepuri.in");
ofstream os("iepuri.out");

#define Mod 30011

int n, k;
int t[101];
//typedef vector<int> VI;
using VI  = vector<int>;
vector<VI > s, G;

int sol;
int aux1, aux2;
int source;

VI Df(int x);

int main()
{
	cin >> n >> k;
	G.resize(n+1);
	s = vector<VI>(n + 1, VI(k + 1, 1));
	
	for(int i = 1; i <= n-1; ++i)
	{
		cin >> aux1 >> aux2;
		t[aux2] = aux1;
		G[aux1].push_back(aux2);
	}
	
	for(int i = 1; i <= n; ++i)
		if(t[i] == 0)
			source = i;
	VI res = Df(source);
	
	for(int i = 1; i <= k; i++)
		sol = (sol + res[i]) % Mod;
	
	cout << sol;
	
	is.close();
	os.close();
	return 0;
}

VI Df(int x)
{
	VI rx(k + 1, 1);
	for( const auto& f : G[x])
	{
		VI rf = Df(f), tmp(k + 1);			
		
		for(int i = 1; i <= k; ++i)
			for(int j = i + 1; j <= k; ++j)
			{
				tmp[i] += (rx[i] * rf[j]) % Mod; 
				if(tmp[i] > Mod)
					tmp[i] -= Mod;
			}
		rx = tmp;
	}
	return rx;
}
