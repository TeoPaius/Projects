#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// clasa de functori
struct Elev {
	Elev(string num = "") : nume(num)  { }
	
	bool operator() (const Elev& e1, const Elev& e2) const
	{
		return e1.nume < e2.nume;
	}
	string nume;
}; 
 
 
int main() 
{
	
	vector<Elev> e { Elev("Ion"), { "Vasile" }, { "Ioana" } };
	Elev el;       // functor
//	sort(e.begin(), e.end(), el);
	
	sort(e.begin(), e.end(), Elev());
	
	for ( const auto & el : e )
		cout << el.nume << ' ';
	
   return 0;
}
