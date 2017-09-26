#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct Elev {
	Elev(string num = "") : nume(num)  { }
	
	string nume;
}; 
 struct Compare {
	bool operator() (const Elev& e1, const Elev& e2) const
	{
		return e1.nume < e2.nume;
	}
};
 
int main() 
{
	
	vector<Elev> e { Elev("Ion"), { "Vasile" }, { "Ioana" } };
	priority_queue<Elev, vector<Elev>, Compare> pq(e.begin(), e.end());
	while ( !pq.empty() )
	{
		cout << pq.top().nume << ' ';
		pq.pop();
	}
   return 0;
}
