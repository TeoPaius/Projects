#include <fstream>
using namespace std;
ifstream is("rafturi.in");
ofstream os("rafturi.out");

int c;
int n;
int d[10001][10001];
int aux[10001];
int s;
int maxim;

int main()
{
    is >> c;
    is >> n;
    int i, j;
    for(int x = 1; x <= n; ++x)
    {
        is >> j >> i;
        d[c - i][j] = 1;
        aux[i] = 1;
    }
    for(int x = 1; x <= c; ++x)
    {

        for(int y = 1; y <= c; ++y)
        {
            os << d[x][y];
            os << ' ';
        }
        os << '\n';
    }
    os << '\n';
    for(int x = 2; x <= n - 1; )
    {
        if(aux[x] == 1 || aux[x - 1] == 1 || aux[x + 1] == 1)
        {
            maxim = 0;
            for(int y = c; y >= 0; --y)
            {
                if(d[y][x] == 1 && c - y + 1 >= maxim)
                {
                    maxim = c - y  + 1;
                }
                if(d[y][x - 1] == 1 && c - y + 1 >= maxim)
                {
                    maxim = c - y  + 1;
                }
                if(d[y][x + 1] == 1 && c - y + 1 >= maxim)
                {
                    maxim = c - y  + 1;
                }
            }
            s += maxim;
            x += 3;
        }
        else
            x++;
    }

    os << s;
    is.close();
    os.close();
    return 0;
}
