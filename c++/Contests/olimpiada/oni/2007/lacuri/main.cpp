#include <fstream>
using namespace std;

ifstream is("lacuri.in");
ofstream os("lacuri.out");

bool Lac(int x, int y);

int n;
int a[101][101];
int lacuri;

int main()
{
    is >> n;
    int ok = true;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n ; ++j)
            is >> a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n ; ++j)
        {
            if(a[i][j] == 1 && a[i-1][j] == 0 && a[i][j - 1] == 0)
            {
                if(Lac( i, j))
                    ++lacuri;
                else
                    ok = false;
            }
        }
    os << lacuri << '\n';
    if(ok)
    {


    }

    is.close();
    os.close();
    return 0;
}

bool Lac(int x, int y)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int lin = x;
    int col = y;
    while(a[x][y] == 1 )
    {
        cnt1++;
        y++;
    }
    y = col;
    while(a[x][y] == 1 )
    {
        cnt2++;
        x++;
    }
    if(cnt1 != cnt2)
        return false;

    for(int i = lin; i < lin + cnt1; ++i)
        for(int j = col; j < col + cnt1; ++j)
            if(a[i][j] == 0)
                return false;
    return true;
}


