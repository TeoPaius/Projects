/*Se citeste o valoare naturala n ,apoi inca n nr intregi .
Sa se afiseza maximul si minimul valorilor citite dintre cele n .
*/

#include <iostream>
using namespace std;

int main ()
{
	int n, x, maxim=-99999, minim=99999;
	cout << "n=  ";
	cin >> n;
	int i = 0;
	while ( i<n )
	{
		cin >> x;
		if ( x > maxim )
			maxim = x;
		if ( x < minim )
			minim = x;
		i++;

	}
	cout << "maximul e " << maxim << '\n';
	cout << "minimul e " << minim;

	return 0;
}



