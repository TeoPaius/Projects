#include <fstream>
using namespace std;
ifstream is ("6.in");
ofstream os ("6.out");

void Citeste(int& n, int c[51]);
int Ok(int a[51], int b[51], int n, int m, int ind);
int Nr(int a[51], int b[51], int n, int m);

int main()
{
    int N, M, a[51], b[51];

    Citeste(N, a);
    Citeste(M, b);

    os << Nr(a, b, N, M);
    is.close();
    os.close();
    return 0;
}

void Citeste(int& n, int c[51])
{
    is >> n;
    for(int i = 0; i < n; ++i)
        is >> c[i];
}

int Ok(int a[51], int b[51], int n, int m, int ind)
{
    for(int i = 0; i < m; ++i)
    {
        if(a[ind] != b[i])
        {
            return 0;
        }
        ind++;
    }
    return 1;
}

int Nr(int a[51], int b[51], int n, int m)
{
    int cnt = 0;
    for(int i = 0; i <= n - m + 1; ++i)
        if(Ok(a, b, n, m, i))
            ++cnt;
    return cnt;
}


