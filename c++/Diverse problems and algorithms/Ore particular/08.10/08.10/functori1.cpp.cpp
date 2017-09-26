#include <iostream>
#include <string>
using namespace std;

struct Elev {
	Elev(string num = "") : nume(num)  { }
	
	void operator() (string text) const
	{
		cout << "Salut " << text;
	}
	string nume;
}; 
 
int main() 
{
	Elev e;  // e - functor, function object (obiect - functie)
 	e("Adriana!");        // e.operator()("Adriana");
 	
 	Elev()("Teodor!");
   return 0;
}
