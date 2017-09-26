#include <fstream>
#include <cstdio>
#include <queue>
using namespace std;
FILE * is = fopen("custi.in", "r");
ofstream os ("custi.out");

struct Cell{
    int i, j;
};

int a[1002][1002];
int iaux, jaux;
int n;
int cnt[1002]; // nr de smatici de lat k
bool Verif(int i, int j, int k);
queue<Cell> b;
int cntaux;
int aux;


int main()
{
    fscanf(is, "%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            fscanf(is, "%d", &a[i][j]);
            if(a[i][j])
            {
                Cell caux;
                caux.i = i;
                caux.j = j;
                b.push(caux);
                cntaux++;
                cnt[1]++;
            }
        }
    for(int k = 2; k <= n; ++k)
    {

        while(cntaux)
        {
            iaux = b.front().i;
            jaux = b.front().j;
            if(Verif(iaux, jaux, k))
            {
                b.push(b.front());
                aux++;
            }
            b.pop();
            cntaux--;
        }
        cntaux = aux;
        cnt[k] = aux;
        aux = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        os << cnt[i];
        os << '\n';
    }
    fclose(is);
    os.close();
    return 0;
}

bool Verif(int i, int j, int k)
{
    for(int x = i; x < i+k-1; ++x)
    {
        if(a[x][j+k-1] == 0)
            return false;
    }
    for(int y = j; y <= j+k-1; ++y)
    {
        if(a[i+k-1][y] == 0)
            return false;
    }
    return true;
}

