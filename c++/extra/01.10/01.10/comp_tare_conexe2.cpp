/* Det componentelor tare conexe
 * O(m)
 */  
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("gr.in");
ofstream fout("gr.out");

typedef vector<int> VI;
vector<VI> cc;
VI c;
typedef VI::iterator IT; 
VI G1[10000], G2[10000];
int n, nrc;
stack<int> stk;

vector<bool> s;
void ReadGraph();
void Df(int x);
void DfT(int x);

int main()
{
	ReadGraph();
	for ( int i = 1; i <= n; ++i )
		if ( !s[i] )
			Df(i);
	s.assign(n + 1, false);
	int i;
	while ( !stk.empty() )
	{
		i = stk.top(); stk.pop();
		if ( !s[i] )
		{
			nrc++;
			c.clear();
			DfT(i);
			cc.push_back(c);
		}
	}
	fout << nrc << " componente tare conexe\n";
	for ( const auto& c : cc)
	{
		for ( const auto& x : c)
			fout << x << ' ';
		fout << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}

void ReadGraph()
{
	int x, y;
	fin >> n;
	s.resize(n + 1); 
	while (fin >> x >> y)
	{
		G1[x].push_back(y);
		G2[y].push_back(x);
	}
}

void Df(int x)
{
	s[x] = true;
	for ( IT it = G1[x].begin(); it != G1[x].end(); ++it )
		if ( !s[*it] )
			Df(*it);
	stk.push(x);
}

void DfT(int x)
{
	s[x] = true;
	c.push_back(x);
	for ( IT it = G2[x].begin(); it != G2[x].end(); ++it )
		if ( !s[*it] )
			DfT(*it);
}

