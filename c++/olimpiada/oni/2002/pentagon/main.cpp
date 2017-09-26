#include <fstream>
using namespace std;
ifstream is("pentagon.in");
ofstream os("pentagon.out");

int perete[201][201];
int m, n;
int k[201];
char nr[201][201];

int main()
{
    is >> n >> m;
    for(int l = 1; l <= n; ++l)
        is >> nr[l];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            perete[i][j] = nr[i][j - 1] - 48;
        }

    int j = 1;
    int i = 1;
    bool ex = true;
    while(j <= m)
    {
        int cnt = 0;
        ex = true;
        while(perete[i][j] == 0 && i <= n)
        {
            cnt++;
            ++i;
            ex = false;
        }
        if(ex)
            ++i;
        k[cnt]++;
        if(i > n)
        {
            i = 1;
            j++;
        }
    }
    for(int z = 1; z <= n; ++z)
        if(k[z] > 0)
        {
            os << z << ' ' << k[z] << '\n';
        }
    is.close();
    os.close();
    return 0;
}
