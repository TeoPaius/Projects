#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream is("test.in");
ofstream os("test.out");

int main()
{
    int dirj[5] = {0,1,0,-1};
    int diri[5] = {1,0,-1,0};
    int cntd = 0;
    int cnt = 1;
    int pas;
    int pozi = 1;
    int pozj = 1;

    int n;
    int a[100];
    int b[100][100];

    is >> n;
    pas = sqrt(n) - 1;

    for(int i = 1; i <= n; ++i)
        is >> a[i];

    for(int i = 1; i <= 3; ++i)
    {
        while(pas > 0)
        {
            b[pozi][pozj] = a[cnt];
            cnt++;
            pozi += diri[cntd];
            pozj += dirj[cntd];
            pas--;
        }
        cntd = (cntd + 1) % 4;
        pas = sqrt(n) - 1;
    }

    pas--;
    while(pas > 0)
    {
        for(int j = 1; j <= 2; ++j)
        {
            for(int i = 1; i <= pas; ++i)
            {
                b[pozi][pozj] = a[cnt];
                cnt++;
                pozi += diri[cntd];
                pozj += dirj[cntd];
            }
            cntd = (cntd + 1) % 4;
        }
        pas--;

    }

    b[pozi][pozj] = a[cnt];

    for(int i = 1; i <= sqrt(n); ++i)
    {
        for(int j = 1; j <= sqrt(n); ++j)
            os << b[i][j] << ' ';
        os << '\n';
    }
    is.close();
    os.close();

    return 0;
}
