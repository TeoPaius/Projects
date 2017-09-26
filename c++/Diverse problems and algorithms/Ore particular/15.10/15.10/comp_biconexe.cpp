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
int nv[100];
int Lmin[100];
vector<vector<int> > comp;
int n, m, k;
vector<int> c;
int aux1, aux2;

void Df(int x, int y, int niv);
void Write();


int main()
{
	is >> n >> m;
	
	G.resize(n+1);
	for(int i = 1; i <= m; ++i)
	{
		is >> aux1 >> aux2;
		G[aux1].push_back(aux2);
		G[aux2].push_back(aux1);
	}
	Df(1, 0, 0);
	Write();
	
	is.close();
	os.close();
	return 0;
}

void Df(int x, int y, int niv)
{
	Lmin[x] = niv;
	nv[x] = niv;
	sel[x] = true;
	for(auto i : G[x])
	{
		if(i == y)
			continue;
		if(!sel[i])
		{
			s.push({x, i});
			Df(i, x, niv + 1);
			Lmin[x] = min(Lmin[x], Lmin[i]);
			if(Lmin[i] >= nv[x])
			{
				k++;
				c.clear();
				while(true)
				{
					aux1 = s.top().first;
					aux2 = s.top().second;
					s.pop();
					c.push_back(aux1);
					c.push_back(aux2);
					if(aux1 == x && aux2 == i)
						break;
				}
				comp.push_back(c);
			
			}
		}
		else
			Lmin[x] = min(Lmin[x], nv[i]);
		
	}
	
}

void Write()
{
	os << comp.size() << '\n';
	for(auto c : comp)
	{
		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		for(const auto& x : c)
			os << x << ' ';
		os << '\n';
		
		
	}
		
}
