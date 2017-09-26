//Code by Patcas Csaba
//Time complexity: O(sqrt(n) + nDivisors ^ 2)
//Space complexity: O(nDivisors)
//Method: Brute force
//Implementation time: 15 minutes

#include <vector>
#include <string> 
#include <set> 
#include <map> 
#include <queue> 
#include <bitset> 
#include <stack>
#include <list>

#include <numeric> 
#include <algorithm> 

#include <cstdio>
#include <fstream>
#include <iostream> 
#include <sstream> 
#include <iomanip>

#include <cctype>
#include <cmath> 
#include <ctime>
#include <cassert>

using namespace std;

#define LL long long
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define VB vector <bool>
#define VI vector <int>
#define VD vector <double>
#define VS vector <string>
#define VLL vector <LL>
#define VPII vector <pair <int, int> >
#define VVI vector < VI >
#define VVB vector < VB >

#define FORN(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORI(it, X) for(__typeof((X).begin()) it = (X).begin(); it !=(X).end(); ++it) 
#define REPEAT do{ 
#define UNTIL(x) }while(!(x)); 

#define SZ size()
#define BG begin() 
#define EN end() 
#define CL clear()
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()

#define IN_FILE "cmmmc.in"
#define OUT_FILE "cmmmc.out"
#define MAX 2000000000

ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);

int test, nSol;
LL n;

LL Gcd(LL x, LL y)
{
	while (y)
	{
		LL z = x % y;
		x = y;
		y = z;
	}
	return x;
}

PLL Solve()
{
	PLL ans = MP(n, n);
	LL gyokN = sqrt(double(n));
	vector<LL> divisors;
	FOR(i, 1, gyokN - 1)
		if (!(n % i)) divisors.PB(i), divisors.PB(n / i);
	if (!(n % gyokN))
		if (gyokN * gyokN == n) divisors.PB(gyokN);
		else divisors.PB(gyokN), divisors.PB(n / gyokN);
	nSol = 1;
	LL minSum = (LL)MAX + MAX + 1;
	FORN(i, divisors.SZ - 1)
		FOR(j, i + 1, divisors.SZ - 1)
		{
			LL aux1 = divisors[i], aux2 = divisors[j], gcd = Gcd(aux1, aux2);
			if (aux1 / gcd * aux2 == n)
			{
				++nSol;
				if (minSum > aux1 + aux2)
				{
					minSum = aux1 + aux2;
					ans = MP(aux1, aux2);
				}
			}
		}
	return ans;
}

int main()
{
	fin >> test;
	FORN(t, test)
	{
		fin >> n;
		PII sol = Solve();
		fout << nSol << " " << sol.X << " " << sol.Y << endl;
	}
	fin.close();
	fout.close();

	return 0;
}