#include <fstream>
using namespace std;

const int mod = 10003;

int pow(int x, int y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	long long aux = pow(x, y / 2);
	aux *= aux;
	if (y & 1)
		aux *= x;
	return aux % mod;
}

ifstream fin("test.in");
ofstream fout("test2.out");

int main()
{
	int a, x, n;
	fin >> n;
	for ( int i = 0; i < n; ++i )
	{
        fin >> x >> a;
        fout << pow(x, a) << '\n';
	}
	fin.close();
	fout.close();
}
