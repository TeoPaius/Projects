#include <fstream>

using namespace std;
ifstream is("hercule.in");
ofstream os("hercule.out");

void Modificare(int x, int y);

struct Celula{
    int x;
    int y;
};

int m, n;
int a[201][201];
bool mod[201][201];
int p[201][201];
Celula drum [4005];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int i1, j1, i2, j2;
int cnt = 1;
int cntaux = 1;
int s = 0;
bool modificat = true;

int main()
{
    is >> m;
    is >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            is >> p[i][j];
            a[i][j] = -1;
        }

    is >> i1 >> j1;
    is >> i2 >> j2;
    a[i1][j1] = 0;
    mod[i1][j1] = true;

    while(a[i2][j2] <= 0 && modificat == true)
    {
        modificat = false;
        cnt = cntaux;
        cntaux = 0;
        for(int i = 1; i <= m && cnt > 0; ++i)
            for(int j = 1; j <= n && cnt > 0; ++j)
            {
                if(a[i][j] == s)
                {
                    cnt--;
                    Modificare(i , j);
                }
            }
        s++;
    }
    os << a[i2][j2] << '\n';

    cnt = 1;
    drum[1].x = i2;
    drum[1].y = j2;

    bool gasit = true;
    while(i2 != i1 || j2 != j1)
    {
        gasit = true;
        for(int i = 0; i <= 8 && gasit == true; ++i)
        {
            if(a[i2 + dx[i]][j2 + dy[i]] == a[i2][j2] - 1)
                if(i2 + dx[i] > 0 && i2 + dx[i] <= m && j2 + dy[i] > 0 && j2 + dy[i] <= n)
                {
                    cnt ++;
                    drum[cnt].x = i2 + dx[i];
                    drum[cnt].y = j2 + dy[i];
                    gasit = false;
                    i2 += dx[i];
                    j2 += dy[i];
                }
        }
    }

    for(int i = cnt - 1; i >= 1; --i)
    {
        os << drum[i].x << ' ' << drum[i].y;
        os << '\n';
    }

    is.close();
    os.close();
    return 0;
}

void Modificare(int x, int y)
{
    for(int i = 0; i < 8; ++i)
    {
        int xv = x + dx[i];
        int yv = y + dy[i];
        if(mod[xv][yv] == false && s + 1 < p[xv][yv] )
            if(xv > 0 && xv <= m && yv > 0 && yv <= n)
            {
                a[xv][yv] = s + 1;
                mod[xv][yv] = true;
                modificat = true;
                cntaux++;
            }
    }
}

