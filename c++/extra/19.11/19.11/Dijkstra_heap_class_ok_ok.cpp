// OK - infoarena
#include <fstream>
#include <vector>
using namespace std;

ofstream fout("dijkstra.out");


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


int n, m;
const int Inf = 0x3f3f3f3f;
vector<vector<pair<int, int> > > G; 
vector<int> D;
void Read();
void Write(const vector<int>& D);
void Dijkstra(int k, vector<int>& D);


int main()
{
	Read();
	Dijkstra(x, D);
		
	Write(D);

	fout.close();
	return 0;
}

bool inHeap;
void Dijkstra(int k, vector<int>& D)
{
	int x, w;
	D = vector<int>(n + 1, Inf);
	D[k] = 0;
	Heap heap(n, D);
	
	heap.push(k);
	
	while ( !heap.empty() )
	{
		k = heap.top();
		heap.pop();
		for (const auto& p : G[k])
		{
			x = p.first, w = p.second;
			if ( D[x] > D[k] + w)
			{
				inHeap = D[x] != Inf;
				D[x] = D[k] + w;
				if ( inHeap )
					heap.up(x);
				else
					heap.push(x);
			}
		}
	}
}

void Read()
{
	ifstream fin("dijkstra.in");
	int a, b, cost;
	fin >> n >> m;
	G.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		fin >> a >> b >> cost;
		G[a].push_back({b, cost});
	}
	
	fin.close();
}

void Write(const vector<int>& D)
{
	for (int i = 2; i <= n; ++i )
		if ( D[i] != Inf)
			fout << D[i] << ' ';
		else
			fout << "0 ";
	fout << '\n';
}

