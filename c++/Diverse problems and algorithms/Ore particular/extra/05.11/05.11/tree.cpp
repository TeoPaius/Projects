#include <fstream>
#include <vector>
using namespace std;

ifstream is("tree.in");
ofstream os("tree.out");

int n, q;
vector<vector<int> > g;
vector<int> ti, tf;
int a, b;
int time;

void Df(int k);

int main()
{
	is >> n;
	g.resize(n + 1);
	ti.resize(n + 1);
	tf.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		is >> a >> b;
		g[a].push_back(b);
		g[b].psuh_back(a);
	}
	Df(1);
	is >> q;
	for(int i = 1; i <= q; ++i)
	{
		is >> a >> b;
		if((ti[a] > ti[b] && tf[a] > tf[b]) || (ti[b] > ti[a] && tf[b] > tf[a]))
			os <<  "da" << '\n';
		else 
			os << "nu" << '\n';
	}
	
}

void Df(int k)
{
	time++;
	ti[k] = time;
	for(const auto& i : g[k])
	{
		if(ti[i] == 0)
			Df(i);
	}
	time++;
	tf[k] = time;
}
