#include <fstream>
using namespace std;

#define N 1025
#define INF 9999

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

ifstream fin("alpin.in");
ofstream fout("alpin.out");

void Read();
void Write(int , int );
void Solve(int , int , int );
bool Inside(int , int );

int a[N][N], b[N][N], Lmax = -9999, imax, jmax, n, p;
int iv, jv;

int main()
{
	Read();
	for ( int i = 1; i <= n; ++i )
		for ( int j =1; j <=n; ++j )
			if ( !b[i][j] )
				Solve(i, j, 1);

	fout << Lmax << '\n';
	Write(imax, jmax);

	fin.close();
	fout.close();
}

void Read()
{
	fin >> n;
	for ( int i = 1; i <= n; ++i )
		for ( int j = 1; j <=n; ++j )
			fin >> a[i][j];
}

void Solve(int i, int j, int p)
{

	if ( b[i][j] < p )
	{
		b[i][j] = p;
		if ( p > Lmax )
		{
			Lmax = p;
			imax = i, jmax = j;
		}
	}

	for ( int d = 0; d < 4; ++d )
	{
		iv = i+di[d];
		jv = j+dj[d];
		if ( Inside(iv, jv ) && a[iv][jv] > a[i][j] )
			Solve (iv, jv, p+1);
	}
}

void Write (int i, int j)
{
	if ( b[i][j] == 1 )
	{
		fout << i << ' ' << j << '\n';
		return;
	}
	int iv, jv;
	for ( int d = 0; d < 4; ++d )
	{
		iv = i+di[d];
		jv = j+dj[d];
		if ( Inside(iv, jv) && b[iv][jv]+1 == b[i][j] )
		{
			Write(iv, jv);
			fout << i << ' ' << j << '\n';
			return;
		}
	}
}

bool Inside(int i, int j)
{
	return i <= n && i > 0 && j > 0 && j <= n;
}
