#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Elev {
	Elev(string num = "") : nume(num)  { }
	bool operator< (const Elev& e) const
	{
		return nume > e.nume;
	}
	string nume;
}; 
 
int main() 
{
	
	vector<Elev> e { Elev("Ion"), { "Vasile" }, { "Ioana" } };
	priority_queue<Elev> pq(e.begin(), e.end());
	while ( !pq.empty() )
	{
		cout << pq.top().nume << ' ';
		pq.pop();
	}
   return 0;
}
