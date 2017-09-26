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
	
	cout << res[k]; // cel mult k
	
	
	is.close();
	os.close();
	return 0;
}

VI Df(int x)
{
	VI rx(k + 1, 1);
	VI Sx(k + 1);
	for ( const auto& f : G[x])
	{
		VI Sf = Df(f);			
		int tmp;
		for (int i = 1; i <= k; ++i)
		{
			tmp = Sf[k] - Sf[i];
			if ( tmp < 0 )
				tmp += Mod;
			rx[i] = (rx[i] * tmp) % Mod;  // i + 1, ..., k
		}
	}
	
	for (int i = 1; i <= k; ++i)
		Sx[i] = (Sx[i - 1] + rx[i]) % Mod;
	
	return Sx;
}
