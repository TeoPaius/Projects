#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Elev {
	Elev(string num = "") : nume(num)  { }
	
	bool operator< (const Elev& e) const
	{
		return nume < e.nume;
	}
	string nume;
}; 
 
int main() 
{
	
	vector<Elev> e { Elev("Ion"), { "Vasile" }, { "Ioana" } };
	sort(e.begin(), e.end());
	
	for ( const auto & el : e )
		cout << el.nume << ' ';
	
   return 0;
}
