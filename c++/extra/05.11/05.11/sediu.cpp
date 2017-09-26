#include <fstream>
#include <vector>
using namespace std;

ifstream is("sediu.in");
ofstream os("sediu.out");

int n, a, b;
int answ = 0x3f3f3f3f, nra;
vector<int> sum, nr, cmax;
vector<vector<int> > g;

void DF(int k);

int main()
{
	is >> n;
	g.resize(n + 1);
	sum.resize(n + 1);
	nr.resize(n + 1);
	cmax.resize(n + 1);
	for ( int i = 1; i < n; ++i )
	{
		is >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	DF(1);
	os << answ << " " << nra << "\n";
	for ( int i = 1; i <= n; ++i )
		if ( nr[i] == answ )
			os << i << " ";
	is.close();
	os.close();
	return 0;
} 

void DF(int k)
{
	sum[k] = 1;
	for ( const auto& i : g[k] )
		if ( !sum[i] )
		{
			DF(i);
			sum[k] += sum[i];
			cmax[k] = max(cmax[k], sum[i]);
		}
	nr[k] = max(cmax[k], n - sum[k]);
	if ( nr[k] < answ )
		answ = nr[k], nra = 1;
	else
		if ( nr[k] == answ ) 
			++nra;
}
