// Sa se det nr de lanturi de lungime K intr-un arbore (cost 1 pe muchii).
// OK (verificat cu evaluator si brut)
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("arb.in");
ofstream fout("arb.out");

template <typename T> void Print(T t)
{
	for ( typename T::iterator it = t.begin(); it != t.end(); ++it)
		fout << *it << ' ';
	fout << '\n';
}

typedef vector<int> VI;
typedef vector<VI> VVI;

vector<bool> s;
VVI G;
int n, K, res;

void Read();
VI Df(int x); // ret nr de lanturi care au capatul de sus in x

int main()
{
	Read();
	Df(1);
	fout << res;
    fout.close();
}

void Read()
{
	fin >> n >> K;
	G = VVI(n + 1);
	s = vector<bool>(n + 1);
	int x, y;
	for (int i = 0; i < n - 1; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	fin.close();
}

VI Df(int x)
{
	s[x] = true;
	VI r(n + 1); // r[i] - nr lanturi de lung i care coboara din x (capatul de sus in x)
	r[0] = 1; // intr-un singur mod se poate avea un lant de lungime 0 care coboara din x
	
	for (const int& y : G[x])
	{
		if ( s[y] ) continue;
		VI son = Df(y);
		for ( int i = 0; i <= K; ++i)       // nu ma intereseaza decat lanturile de lungime K
			res += r[i] * son[K - i - 1];   // care au intermediar pe x (si nu urca mai sus)
			
		r[1]++;  // muchia spre fiu
		for (int i = 2; i <= K; ++i)   // acum lanturilor care coboara din x li se mai adauga cele care coboara din son
			r[i] += son[i - 1];        // scad muchia de legatura
	}
//	fout << "nod: " << x << '\n';
//	Print(r);
	return r;
}

