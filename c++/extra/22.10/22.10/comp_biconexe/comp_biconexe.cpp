#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

ifstream is("comp.in");
ofstream os("comp.out");

vector<vector<int > > G;
bool sel[100];
stack<pair<int, int> > s;
int niv[100];
int Lmin[100];
vector<vector<int> > comp;
int n, m, k;
vector<int> c;
int x1, x2;

void Df(int x, int y, int niv);
void Write();


int main()
{
	is >> n >> m;
	
	G.resize(n + 1);
	for(int i = 1; i <= m; ++i)
	{
		is >> x1 >> x2;
		G[x1].push_back(x2);
		G[x2].push_back(x1);
	}
	Df(1, 0, 0);
	Write();
	
	is.close();
	os.close();
	return 0;
}

void Df(int x, int t, int nv)
{
	Lmin[x] = nv;
	niv[x] = nv;
	sel[x] = true;
	for (auto y : G[x])
	{
		if (y == t)
			continue;
		if(!sel[y])
		{
			s.push({x, y});
			Df(y, x, niv + 1);
			Lmin[x] = min(Lmin[x], Lmin[y]);
			if (Lmin[y] >= niv[x])
			{
				//k++;
				c.clear();
				while (true)
				{
					x1 = s.top().first;
					x2 = s.top().second;
					s.pop();
					c.push_back(x1);
					c.push_back(x2);
					if (x1 == x && x2 == y)
						break;
				}
				comp.push_back(c);
			}
		}
		else
			Lmin[x] = min(Lmin[x], niv[y]);
		
	}
	
}

void Write()
{
	os << comp.size() << '\n';
	for (auto& c : comp)
	{
		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		for (const auto& x : c)
			os << x << ' ';
		os << '\n';
		
		
	}
		
}
