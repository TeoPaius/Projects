#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream is("asmax.in");
ofstream os("asmax.out");

int n, a, b, answ = -0x3f3f3f3f;
vector<int> v, smax;
vector<vector<int> > g;
bitset<16001> ok;

void DF(int k);

int main()
{
	is >> n;
	v.resize(n + 1);
	smax.resize(n + 1);
	g.resize(n + 1);
	for ( int i = 1; i <= n; ++i )
	{
		is >> v[i];
		smax[i] = v[i];
	}
	for ( int i = 1; i < n; ++i )
	{
		is >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DF(1);
	for ( int i = 1; i <= n; ++i )
		if ( smax[i] > answ )
			answ = smax[i];
	os << answ;
	is.close();
	os.close();
	return 0;
}

void DF(int k)
{
	ok[k] = true;
	for ( auto& i : g[k] )
		if ( !ok[i] )
		{
			DF(i);
			if ( smax[i] > 0 )
				smax[k] += smax[i];
		}
}
/*
void DF(int k)
{
	ok[k] = true;
	for ( size_t i = 0; i < g[k].size(); ++i )
		if ( !ok[g[k][i]] )
		{
			DF(g[k][i]);
			if ( smax[g[k][i]] > 0 )
				smax[k] += smax[g[k][i]];
		}
}
*/
