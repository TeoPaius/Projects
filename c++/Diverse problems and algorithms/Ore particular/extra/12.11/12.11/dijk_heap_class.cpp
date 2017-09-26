// OK infoarena
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int Inf = 0x3f3f3f3f;
vector<int> D;
vector<vector<pair<int, int> > > G; 
int n, m;
bool inHeap;

class Heap {
public:
	Heap(int n = 0) : nH(0), H(vector<int>(n + 1)), P(vector<int>(n + 1))
	{}
	void pop() 
	{
		Swap(1, nH--);
		int p = 1, s = 2;
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
};

void Dijkstra(int k, vector<int>& D);
void Read();
void Write();

int main()
{
	Read();
	Dijkstra(1, D);
	Write();
	fout.close();
	return 0;
}

void Dijkstra(int k, vector<int>& D)
{
	D = vector<int>(n + 1, Inf);
	Heap heap(n);
	int x, w;
	
	D[k] = 0; 
	heap.push(k);
	while ( !heap.empty() )
	{
		k = heap.top();
		heap.pop();
		
		for (const auto& p : G[k]) 
		{
			x = p.first, w = p.second;
			if (D[x] > D[k] + w)
			{
				inHeap = (D[x] != Inf); 
				D[x] = D[k] + w;
				if (inHeap) 
					heap.up(x);
				else
					heap.push(x);
			}
		}
	}
}

void Read()
{
	fin >> n >> m;
	G.resize(n + 1);
	int a, b, cost;
	for (int i = 0; i < m; ++i)
	{
		fin >> a >> b >> cost;
		G[a].push_back({b, cost});
	}
	fin.close();
}

void Write()
{
	for (int i = 2; i <= n; ++i)
		if ( D[i] != Inf )
			fout << D[i] << ' ';
		else
			fout << "0 "; 
}
