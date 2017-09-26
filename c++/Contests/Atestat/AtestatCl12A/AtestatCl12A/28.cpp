#include <fstream>
#include <cmath>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");


int main()
{
    int n;
    is >> n;
    int x;
    int i = 1;
    int j = 1;
    int l = sqrt(n);
    int a[100][100];
    for(int k = 1; k <= l/2; ++k)
    {
        for(int j = k; j <= l-k; ++j)
        {
            is >> x;
            a[j][k] = x;
        }
        for(int j = k; j <= l-k; ++j)
        {
            is >> x;
            a[l-k+1][j] = x;
        }
        for(int i = l- k+1; i > k; --i)
        {
            is >> x;
            a[i][l-k+1] = x;
        }
        for(int j = l-k+1; j > k; --j)
        {
            is >> x;
            a[k][j] = x;
        }
    }
    if(l % 2 == 1)
    {
        is >> x;
        a[l/2+1][l/2+1] = x;
    }
    for(int i = 1; i <= l; ++i)
    {
        for(int j = 1; j <= l; ++j)
        {
            os << a[i][j] << ' ';
        }
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}

