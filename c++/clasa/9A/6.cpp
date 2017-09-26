/*Se citeste o valoare naturala n ,apoi inca n nr intregi .
Sa se afiseza maximul nr impare  .
*/

#include <iostream>
using namespace std;

int main ()
{
	int n, x, maxim=-99999;
	cout << "n=  ";
	cin >> n;
	int i = 0;
	while ( i<n )
	{
		cin >> x;
		if ( x%2==1 && x > maxim )
			maxim = x;
	i++;

	}
	cout << "maximul e " << maxim;

	return 0;
}



