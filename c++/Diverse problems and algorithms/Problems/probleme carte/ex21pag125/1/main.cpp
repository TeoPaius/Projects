#include <fstream>
using namespace std;
ifstream is ("1.in");
ofstream os ("1.out");

int main()
{
    int a[100][100];
    int cnt = 0;
    int n, m;
    is >> n >> m;
    bool ok;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < m; ++j)
            is >> a[i][j];
    for ( int i = 0; i < n; ++i )
    {
        ok = true;
        for ( int j = 0; j < m - 1; ++j)
        {
            if ( a[i][j] != a[i][j + 1])
                ok = false;
        }
        if (ok)
            cnt++;
    }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
