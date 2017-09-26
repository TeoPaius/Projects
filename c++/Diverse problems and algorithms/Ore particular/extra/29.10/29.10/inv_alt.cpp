#include <cstdio>
#include <algorithm>
#include <vector>

#define ub(x) (x&(-x))
#define NMAX 100001
#define MOD 9917
using namespace std;

vector <pair<int, int>> V;
int A[NMAX], N;
long long sol;

void Update(int x)
{
	for (int i = x; i <= N; i+= ub(i)) 
		A[i]++;
}

int Query(int x)
{
	int S = 0;
	for (int i = x; i > 0; i -= ub(i)) 
		S += A[i];
	return S;
}

template <class T>
struct Funct {
	bool operator ()(const T & p1, const  T & p2 ) const
	{
		return p1.first > p2.first;
	}
};

int main()
{
	freopen("inv.in","r",stdin);
	freopen("inv.out","w",stdout);
	scanf("%d",&N); 
	int x;
	for (int i = 1;i <= N; i++)
	{
		scanf("%d", &x);
		V.push_back({x, i});
	}
//	sort(V.begin(),V.end(), Funct<pair<int, int>>());
	sort(V.begin(),V.end(), greater<pair<int, int>>());
	
	for (int i = 0; i < N; i++)
	{
		x = V[i].second;
		sol += 1LL * Query(x);
		Update(x);
	}
	printf("%lld\n", sol % MOD);
	return 0;
}