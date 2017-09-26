#include <iostream>
using namespace std;

int main ()
{
	int n, s = 0;
	cout << " n=  ";
	cin >> n;
	int x = 1;
	while ( x <= n )
	{
		s = s + x;
		x++;
	}
	cout << "suma este " << s << ' \n ';
	return 0;
}



