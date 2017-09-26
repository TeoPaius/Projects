#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Elev {
	Elev(string num = "") : nume(num)  { }
	string nume;
}; 
 
bool Cmp(const Elev& e1, const Elev& e2)
{
	return e1.nume < e2.nume;
}
 
int main() 
{
	
	vector<Elev> e { Elev("Ion"), { "Vasile" }, { "Ioana" } };

	sort(e.begin(), e.end(), Cmp);
	
//	sort(e.begin(), e.end(), Elev());
	
	for ( const auto & el : e )
		cout << el.nume << ' ';
	
   return 0;
}
