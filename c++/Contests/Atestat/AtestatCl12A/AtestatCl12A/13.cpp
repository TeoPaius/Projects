#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");


int main()
{
    int n;
    int a[100][100];
    int p[100];
    int aux;

    is >> n;

    for(int i = 1; i <= n; ++i)
        p[i] = i;
    for(int i = 1; i <= n; ++i)
    {
        aux = p[1];
        a[i][1] = p[1];
        for(int j = 2; j <= n; ++j)
        {
            a[i][j] = p[j];
            p[j-1] = p[j];
        }
        p[n] = aux;

    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            os << a[i][j] << ' ';
        os << '\n';
    }
    return 0;
}


