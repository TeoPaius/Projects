/* Se citeste  o valoare naturala n ,apoi inca n nr intregi .
Sa se scrie pe ecran nr de valori pare citite  dintre cele n  .
*/

#include <iostream>
using namespace std;

int main ()
{
	int n, x, pare=0, i=0;
	cout << "n=  ";
	cin >> n;
	while (i<n)
	{
		cout << "x=  ";
		cin >> x;
		if ( x%2==0 )
			pare++;
		i++;
	}
	cout << pare;

	return 0;
}



