// Solutie pt 25pct, fara numere mari

#include <fstream>
#include <cmath>

using namespace std;

ifstream f("culori.in");
ofstream g("culori.out");

int n;

int main()
{
	int k;
	long long v=0;
	f>>n;
	if (n==1)
		g<<"5\n";
	else
		if (n==2)
			g<<"8\n";
		else
			if (n==3)
				g<<"14\n";
			else
			{
				if (n%2==0)
					v=8;
				else
					v=14;
				
				k=n/2;
				v=v*round(pow((double)3,k-1));
				g<<v<<"\n";
			}
	g.close();
}