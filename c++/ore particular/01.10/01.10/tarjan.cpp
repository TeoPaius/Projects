#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("gr.in");
ofstream fout("gr.out");

typedef vector<int> VI;
vector<VI> cc;
VI c, niv, L;
typedef VI::iterator IT; 
VI G[10000];
int n, m; // m nr de muchii
stack<int> stk;

vector<bool> s;
void ReadGraph();
void Df(int x, int nv);

int main()
{
	ReadGraph();
	for ( int i = 1; i <= n; ++i )
		if ( !s[i] )
			Df(i, 0);
			
	fin.close();
	fout.close();
	return 0;
}

void Df(int x, int nv)
{
	niv[x] = L[x] = nv;
	s[x] = true;
	stk.push(x);
	for (auto& y : G[x])
		if ( !s[y] )             // [x y] muchie de arbore
		{
			Df(y, nv + 1);
			L[x] = min(L[x], L[y]);
		}
		else    // muchie de intoarcere
			if ( in_stack(y)
				L[x] = min(L[x], niv[y]);
	
	 
	if ( L[x] == niv[x] ) // x e reprezentantul componentei conexe		
	{
		c.clear();
		int y;
		do 
		{
			y = stk.top();
			c.push_back(y);
			stk.pop(); in_stack(y) = false;
		}	while ( y != x );
		cc.push_back(c);
	}
}


void ReadGraph()
{
	int x, y;
	fin >> n >> m;
	s = vector<bool>(n + 1); 
	L = niv = VI(n + 1);
	while (fin >> x >> y)
		G[x].push_back(y);
}

void Write()
{
	fout << cc.size() << '\n';
	for ( const auto& c : cc)
	{
		for ( const auto& x : c)
			fout << x << ' ';
		fout << '\n';
	}

}
