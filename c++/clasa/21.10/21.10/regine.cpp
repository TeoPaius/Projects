#include <fstream>
#include <cmath>
using namespace std;

ifstream is("regine.in");
ofstream os("regine.out");

int x[30]; // x[k] = i (plasam o regina pe linia i si col k)
int n;     // nr de regine  
int nrsol;

void Regine(int k);
bool Ok(int k);
void Write(int k);

int main()
{
	is >> n;
	Regine(1);
	return 0;
}

void Regine(int k)
{
	if ( k > n )
	{
		Write(k - 1);
		return;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		x[k] = i;
		if ( Ok(k) )
			Regine(k + 1);
	}
}

bool Ok(int k)
{
	for (int j = 1; j < k; ++j)
	{
		if ( x[j] == x[k] ) // atac pe orzontala
			return false;
		if ( abs(x[k] - x[j]) == k - j ) // atac pe diagonala
			return false;
	}
	return true;
}

void Write(int k)
{
	os << "Solutia nr. " << ++nrsol << ":\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if ( x[j] == i ) // la linia i si col j se gaseste o regina
				os << " R ";
			else
				os << " * ";
		os << '\n';
	}
	os << "\n\n";
}










