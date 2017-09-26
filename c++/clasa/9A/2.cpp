#include <iostream>
using namespace std;

int main ()
{
	int n, s, x;
	cout << " n=  ";
	cin >> n;
	x = 1;
	s = 0;
	while ( x <= n )
	{
		s = x * x + s;
		x++;
	}
	cout << "suma este " << s ;
	return 0;
}



