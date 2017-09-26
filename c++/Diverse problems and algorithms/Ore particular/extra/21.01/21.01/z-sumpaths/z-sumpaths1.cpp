// Nr total de lanturi de suma M
#include <cstdio>
#include <vector>
using namespace std;

#define MaxN 50024
#define MaxM 104
#define MOD 321555123LL

int n, m;
vector<int> adj[MaxN], cost[MaxN];
//long long dp[MaxN][MaxM], ans;
int dp[MaxN][MaxM], ans;

void Dfs(int u) 
{
	dp[u][0] = 1;
	for(int i = 0; i < (int)adj[u].size(); i++) 
	{
		int v = adj[u][i], w = cost[u][i];
		if(dp[v][0]) continue;
	
		Dfs(v);
		for(int j = 0; j <= m - w; j++) 
			ans = (ans + 1LL * dp[v][j] * dp[u][m - j - w]) % MOD;
			
		for(int j = m; j >= w; j--) 
			dp[u][j] = (dp[u][j] + dp[v][j - w]) % MOD;
	}
}

int main() 
{
	
	int a, b, c;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i < n; i++) 
	{	
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(b), cost[a].push_back(c);
		adj[b].push_back(a), cost[b].push_back(c);
	}
	
	Dfs(1);
	
	printf("%d\n", ans);
	
	//printf("%lld\n", ans);
	return 0;
}
