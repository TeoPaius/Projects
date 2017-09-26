#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

const char iname[] = "arbore.in";
const char oname[] = "arbore.out";
const int maxn = 100005;
const int mod = 666013;
const int phi = 666011;

ifstream f(iname);
ofstream g(oname);

int pow(int x, int y) {
	if (y == 0) 
		return 1;
	if (y == 1)
		return x;
	long long aux = pow(x, y / 2);
	aux *= aux;
	if (y & 1)
		aux *= x;
	return aux % mod;
}

vector<int> E[maxn];
int many[maxn], pos[maxn], N, fact[maxn], ifact[maxn];

void dfs(int x) {
	pos[x] = 1;
	++many[x];
	for (vector<int>::iterator it = E[x].begin(); it != E[x].end(); ++it)
		if (many[*it] == 0) {
			dfs(*it);
			pos[x] = (static_cast<long long>(pos[x]) * ifact[many[*it]] * pos[*it]) % mod;
			many[x] += many[*it];
		}
	pos[x] = (static_cast<long long>(pos[x]) * fact[many[x] - 1]) % mod;
	//fprintf(stderr, "%d -> %d\n", x, pos[x]);
}
	
int main() {
	f >> N;
	for (int i = 1; i < N; ++i) {
		int x, y;
		f >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= N; ++i)
		fact[i] = (static_cast<long long>(fact[i - 1]) * i) % mod,
		ifact[i] = pow(fact[i], phi);
	dfs(1);
	g << pos[1] << "\n";
}
