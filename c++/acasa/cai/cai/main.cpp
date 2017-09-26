#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream is("cai.in");
ofstream os("cai.out");

void Read();
void Solve();
void Write();
bool Ok(int a, int b);

int T, n, aux, cnt;
int c[100][100];
vector<int> G;
vector<int> I;

int main()
{
    is >> T;
    for(int i = 1; i <= T; ++i)
    {
        cnt = 0;
        Read();
        Solve();
        Write();
    }
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n;
    for(int i = 0; i < n; ++i)
    {
        is >> aux;
        G.push_back(aux);
    }
    for(int i = 0; i < n; ++i)
    {
        is >> aux;
        I.push_back(aux);
    }
}

void Write()
{
    os << cnt << '\n';
    G.clear();
    I.clear();
}

bool Ok(int a, int b)
{
    return a < b;
}

void Solve()
{
    sort(G.begin(), G.begin() + n, Ok);
    sort(I.begin(), I.begin() + n, Ok);
    for(int j = 1; i < n; ++i)
        for(int i = j-1; i < n; ++i)
        {
            if(G[i+1] > )
            c[i][j] = max(c[i+1][j])
        }
}
