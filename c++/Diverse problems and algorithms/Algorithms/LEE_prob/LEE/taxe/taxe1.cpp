#include <fstream>
#include <queue>
using namespace std;
#define DIM 100
// #define INF 100
const int INF = INT_MAX;
const int di[] = { -1, 0, 1, 0}, 
	      dj[] = { 0, 1, 0, -1 }; 

queue<pair<int, int> > Q;    // coada vida
int n, S;
int b[DIM][DIM];    // taxele
int a[DIM][DIM];

void Read();
void Solve();

int main()
{
	Read();
	Solve();
	ofstream fout("taxe.out");
	if ( S >= a[n-1][n-1] )
		fout << S - a[n-1][n-1] << '\n';
	else
		fout << "-1\n";

	fout.close();
	
	
	return 0;
}


void Read()
{
	ifstream fin("taxe.in");
	fin >> S >> n;
	for ( int i = 0; i < n; ++i )
		for ( int j = 0; j < n; ++j )
		{
			fin >> b[i][j];
			a[i][j] = INF;
		}
	fin.close();
	
}

bool Inside(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}


void Solve()
{
	a[0][0] = b[0][0];
	// Q.push(pair<int, int>(0, 0) );
	Q.push(make_pair(0, 0) );
	int i, j, iv, jv;
	pair<int, int> x;
	while ( !Q.empty() )
	{
		x = Q.front(); Q.pop();
		i = x.first; j = x.second;
		for ( int d = 0; d < 4; ++d )
		{
			iv = i + di[d];
			jv = j + dj[d];
			if ( Inside(iv, jv) && a[iv][jv] > a[i][j] + b[iv][jv] )
			{
				a[iv][jv] = a[i][j] + b[iv][jv];
				Q.push(make_pair(iv, jv));
			//	x.first = iv; x.second = jv; 
			//	Q.push(x);
			}
		}
	//	Q.pop();
	}
	
}















