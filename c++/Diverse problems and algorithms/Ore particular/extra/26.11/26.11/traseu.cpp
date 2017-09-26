#include <fstream>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("traseu.in");
ofstream os("traseu.out");

int n, m;
int cmin, x, y, z;

vector<vector<pair<int, int> > > g;
vector<int> d, t;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void Read();
void Dijkstra(int nod);
void Write();
void Write2(int nod);

int main()
{
	Read();
	cmin = INF;
	for ( int i = 1; i <= n; ++i )
	{
		d.assign(n + 1, INF);
		Dijkstra(i);
		for ( int nod = 1; nod <= n; ++nod )
			for ( const auto& j : g[nod] )
				if ( t[j.second] != nod && t[nod] != j.second )
					if ( cmin > d[nod] + d[j.second] + j.first )
					{
						cmin = d[nod] + d[j.second] + j.first;
						x = nod;
						y = j.second;
						z = i;
					}
	}
	Write();
	is.close();
	os.close();
	return 0;
}
void Write()
{
	os << x << " ";
	while ( t[x] != z )
	{
		os << t[x] << " ";
		x = t[x];
	}
	Write2(y);
}

void Write2(int nod)
{
	if ( nod == z )
	{
		os << nod;
		return;
	}
	Write2(t[nod]);
	os << nod << " ";
}

void Dijkstra(int nod)
{
	int cost;
	d[nod] = 0;
	t[nod] = 0;
	q.push(make_pair(0, nod));
	while ( !q.empty() )
	{
		nod = q.top().second;
		cost = q.top().first;
		q.pop();
		if ( cost > d[nod] )
			continue;
		for ( const auto& i : g[nod] )
			if ( d[i.second] > d[nod] + cost )
			{
				d[i.second] = d[nod] + cost;
				t[i.second] = nod;
				q.push(make_pair(d[i.second], i.second));
			}
	}
}

void Read()
{
	int n1, n2, cost;
	is >> n >> m;
	g.resize(n + 1);
	d.resize(n + 1);
	t.resize(n + 1);
	for ( int i = 1; i <= m; ++i )
	{
		is >> n1 >> n2 >> cost;
		g[n1].push_back(make_pair(cost, n2));
	}
}
