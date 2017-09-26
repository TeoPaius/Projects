#include <fstream>
#include <algorithm>
using namespace std;

#define FOR(i, n) for ( int i = 0; i < n; ++i )

const int MAX = 100;
int aib[MAX][MAX];
int n; // nr puncte


ifstream is("puncte.in");
ofstream os("puncte.out");

int Query(int x, int y)
{
	int sum = 0;
	for ( int i = x; i; i -= i & -i )
		for ( int j = y; j; j -= j & -j )
			sum += aib[i][j]; 
	return sum;
}

void Update(int x, int y, int val)
{
	for ( int i = x; i <= MAX; i += i & -i )
		for ( int j = y; j <= MAX; j += j & -j )
			aib[i][j] += val;
}

int main()
{
	int x, y, a;
	is >> n;
	FOR(i, n)
	{
		is >> a >> x >> y;
		if ( a == 0 ) // adauga punct
			Update(x, y, 1);
		if ( a == 1 )
			Update(x, y, -1);  // sterg un punct
		if ( a == 2 )
			os << Query(x, y) << '\n';
	}
	
	is.close();
	os.close(); 
	return 0;
}
