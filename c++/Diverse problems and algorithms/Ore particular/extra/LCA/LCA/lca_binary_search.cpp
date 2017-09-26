// LCA cu binary-search 
// Retin toate caile de la frunze spre radacina 
// Pt o cale x---> root, caut binar LCA in functie de pozitia LCA pe cale
#include <fstream>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

#define DIM 501
ifstream fin("graf.in");
ofstream fout("graf.out");

int a[DIM][DIM];
int g[501];
int td[2*DIM+1], tf[2*DIM+1], t;
vector<deque<int> > paths;
vector<int> path_id, path_offset;
deque<int> this_path;

bool v[DIM];
int m, n;
 
void Load();
void DF(int x);
int LCA(int, int);

int main()
{
	Load();
	path_id.resize(n + 1);
	path_offset.resize(n + 1);

	DF(1);
	unsigned int i, j;

	for (  i = 0; i < paths.size(); ++i )
	{
		fout << "drumul " << i << " : ";
		for (  j = 0; j < paths[i].size(); ++j )
		{
			fout <<  paths[i][j] << ' ';
			path_id[ paths[i][j] ] = i;
		//	fout << i << ' ';
			path_offset[ paths[i][j] ] = j;
		}
		fout << '\n';
	}

	for (  i = 0; i < paths.size(); ++i )
	{
		fout << "drumul " << i << " : ";
		for (  j = 0; j < paths[i].size(); ++j )
		{
		//	fout <<  paths[i][j] << " ";
			if ( path_id[paths[i][j]] == i )
				fout << paths[i][j] << "  [ " << path_offset[paths[i][j]] << " ] ";;
		//	fout << path_offset[ paths[i][j] ] << ' ';
		}
		fout << '\n';
	}
/*	fout << '\n';
	for ( int i = 1; i <= n; ++i )
		fout << i << ' ' << path_id[i] << ' ' << path_offset[i] << '\n';
	*/
	fout << "\n\n";
	fout << LCA(6, 13);
	fin.close();
	fout.close();
	return 0;
}

void DF(int x)
{
	this_path.push_front(x);
	td[x] = ++t;
	v[x] = true;
	for (int i = 1; i <= n; ++i )
		if ( !v[i] && a[x][i] )
			DF(i);
	if ( g[x] == 1 )      // gradul exterior este 0
		paths.push_back(this_path);
	this_path.pop_front(); // scot nodul din stiva la terminare		
	tf[x] = ++t;
}

bool IsAncestor(int x, int y) // x e stramosul lui y
{
	return td[x] < td[y] && tf[y] < tf[x];
}

int LCA(int x, int y)
{
	if ( IsAncestor(x, y) ) return x; 
	if ( IsAncestor(y, x) ) return y;

	int p_id = path_id[x]; 
	int lo = path_offset[x], hi = paths[p_id].size() - 1;
	int m, lca = paths[p_id][hi];
	cout << "lo = " << lo << "p_id = " << p_id << " hi = " << hi << " lca = " << lca; cin.get();
	while ( lo <= hi )
	{
		m = (lo + hi) / 2;
		if ( IsAncestor(paths[p_id][m], y) ) 
		{
			lca = paths[p_id][m];
			hi = m - 1;
		}
		else
			lo = m + 1;	
	}
	return lca;
}

void Load()
{
	int x, y;
	fin >> n;
	for (int i = 0; i < n; ++i ) // graful e arbore
	{
		fin >> x >> y;
		g[x]++; g[y]++;
		a[x][y] = a[y][x] = 1;	
	}
}

