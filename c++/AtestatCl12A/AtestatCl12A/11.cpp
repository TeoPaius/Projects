#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

int Suma(int x[100][100], int n, int p);

int main()
{
    int n;
    is >> n;
    int x[100][100];
    int s;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            is >> x[i][j];
        s = Suma(x,n,i);
        if (s % 2 == 0)
            os << i << ' ';
    }

    return 0;
}

int Suma(int x[100][100], int n, int p)
{
    int s = 0;
    for(int i = 1; i <= n; ++i)
        s += x[p][i];
    return s;

}
