// O(n + m)
#include <fstream>
#include <vector>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("ctc.in");
ofstream os("ctc.out");

int n, m, a, b;
int nv;
vector<vector<int> > G, cc;
vector<int> niv, L, c;
bitset<1000000> inStack;
stack<int> stk;

void Tarjan(int nod);

int main()
{
    is >> n >> m;
    
    G.resize(n + 1);
    niv = L = vector<int>(n + 1);
    
    for ( int i = 1; i <= m; ++i )
    {
        is >> a >> b;
        G[a].push_back(b);
    }
    
    for ( int i = 1; i <= n; ++i )
        if ( niv[i] == 0 )
            nv = 0, Tarjan(i);
    
    os << cc.size() << "\n";
  
	for (const auto& c : cc)
    {
		for (const auto& x : c)
			os << x << ' ';
		os << '\n';
	}  
    is.close();
    os.close();
    return 0;
}

void Tarjan(int x)
{
    niv[x] = L[x] = ++nv;
    stk.push(x);
    inStack[x] = true;
    
    for ( const auto& y : G[x] )
        if ( niv[y] == 0 ) // muchie de arbore
        {
            Tarjan(y);
            L[x] = min(L[x], L[y]);
        }
        else  // sa fie muchie de intoarcere, nu muchie transversala
            if ( inStack[y] )
                L[x] = min(L[x], niv[y]);
    
    // daca nod e radacina, scoatem din stiva comp tare conexa curenta (stiva nu se goleste neaparat)
    if ( niv[x] == L[x] )
    {
        c.clear();
        int x2;
        while ( true )
        {
            c.push_back(x2 = stk.top());
            stk.pop();
            inStack[x2] = false;
            if ( x2 == x ) 
				break;
        } 
        cc.push_back(c);
    }
}
