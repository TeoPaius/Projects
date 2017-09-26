#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream is("gems.in");
ofstream os("gems.out");

vector<vector<int> > g; 

int s[10001][4];
int m;
int n1, n2;
void Df(int node);
bool viz[100001];
int main()
{
	
	cin >> m;
	g.resize(m+1);
	for(int  i = 1; i < m; ++i)
	{
		cin >> n1 >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	} 
	Df(1);
	cout << min(min(s[1][1], s[1][2]), s[1][3]);
	
	is.close();
	os.close();
	return 0;
		
}

void Df(int node)
{
	s[node][1] = 1;
	s[node][2] = 2;
	s[node][3] = 3;
	viz[node] = true;
	for(const auto& i : g[node])
	{
		if(viz[i])
			continue;
		Df(i);
		s[node][1] += min(s[i][2], s[i][3]);
		s[node][2] += min(s[i][1], s[i][3]);
		s[node][3] += min(s[i][1], s[i][2]);
	} 
	
}
