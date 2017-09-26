/* Sort Topologica
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
VI G[10000];
int n;
stack<int> stk;

vector<bool> s;
void ReadGraph();
void Df(int x);

int main()
{
	ReadGraph();
	for ( int i = 1; i <= n; ++i )
		if ( !s[i] )
			Df(i);
	int i;
	while ( !stk.empty() )
	{
		fout << stk.top() << ' ';
		stk.pop();
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
		G[x].push_back(y);
	}
}

void Df(int x)
{
	s[x] = true;
	for ( const int& y : G[x] )
		if ( !s[y] )
			Df(y);
	stk.push(x);
}


