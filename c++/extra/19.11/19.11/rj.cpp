#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
#define nodv g[k][i].second
#define costv g[k][i].first
using namespace std;

ifstream is("rj.in");
ofstream os("rj.out");

class Heap {
public:
	Heap(int n, const vector<int>& _D) 
		: nH(0), 
		H(vector<int>(n + 1)), 
		P(vector<int>(n + 1)),
		D(_D)
	{}
	
	void pop(int node = -1) 
	{
		int p;
		if ( node == -1 )
			p = 1;
		else
			p = P[node];
		
		Swap(p, nH--);
		int s = 2 * p;
		while ( s <= nH ) 
		{
			if ( s + 1 <= nH && D[H[s + 1]] < D[H[s]] )
				s++;
			if ( D[H[s]] < D[H[p]] )
			{				
				Swap(s, p);	
				p = s;	
				s = 2 * p;
			}
			else break;
		}
	}
	
	void push(int node) 
	{
		H[++nH] = node;	P[node] = nH;
		up(node);
	}
	
	void up(int node) 
	{
		int s = P[node], p = s / 2;
		while ( p != 0 && D[H[s]] < D[H[p]] ) 
		{
			Swap(p, s);	
			s = p; p = s / 2;
		}
	}
	
	bool empty() const
	{
		return nH <= 0;
	}
	int top() const
	{
		return H[1];
	}
	
private:
	void Swap(int s, int p) 
	{
		swap(H[s], H[p]);
		P[H[p]] = p;
		P[H[s]] = s;
	}
	int nH;
	vector<int> H, P;
	const vector<int> &D;  // obligatoroiu referinta constanta, altfel D e o copie a lui ::D
};

int n, m, r1, r2, J1, j2;
vector<vector<pair<int, int> > > g;
vector<int> dr, dj;
vector<bool> sr, sj;

void Dijkstra(int nods, vector<int>& d);
void DF(int k, vector<int>& d, vector<bool>& s);
void Write(vector<int>& d);
int main()
{
	is >> n;
	int answ;
	while ( n != -1 )
	{
		is >> m >> J1 >> j2 >> r1 >> r2;
		g.clear();
		g.resize(n + 1);
		sr.resize(n + 1, false);
		sj.resize(n + 1, false);
		int n1, n2, cost;
		while ( m-- )
		{
			is >> n1 >> n2 >> cost;
			g[n1].push_back(make_pair(cost, n2));
			g[n2].push_back(make_pair(cost, n1));
		}
		Dijkstra(J1, dj);
		DF(j2, dj, sj);
		Dijkstra(r1, dr);
		DF(r2, dr, sr);
	
		answ = INF;
		for ( int i = 1; i <= n; ++i )
			if ( sj[i] && sr[i] && dj[i] == dr[i] )
				answ = min(answ, dj[i]);
		if ( answ != INF )
			os << answ << "\n";
		else
			os << "-1\n";
		is >> n; 
	}
	is.close();
	os.close();
	return 0;
}

void Write(vector<int>& d)
{
	for (const auto& x : d)
		os << x << ' ';
	os << '\n'; 
}

void Dijkstra(int k, vector<int>& D)
{
	bool inHeap;
	int x, w;
	D = vector<int>(n + 1, INF);
	D[k] = 0;
	Heap heap(n, D);
	
	heap.push(k);
	
	while ( !heap.empty() )
	{
		k = heap.top();
		heap.pop();
		for (const auto& p : g[k])
		{
			w = p.first, x = p.second;
			if ( D[x] > D[k] + w)
			{
				inHeap = D[x] != INF;
				D[x] = D[k] + w;
				if ( inHeap )
					heap.up(x);
				else
					heap.push(x);
			}
		}
	}
}

void DF(int k, vector<int>& d, vector<bool>& s)
{
	s[k] = true;
	for ( size_t i = 0; i < g[k].size(); ++i )
		if ( d[k] == d[nodv] + costv )
			if ( !s[nodv] )
				DF(nodv, d, s);
}
