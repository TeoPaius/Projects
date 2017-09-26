#include <fstream>
using namespace std;
ifstream is("becuri.in");
ofstream os("becuri.out");

int m, n;
int b[101][101];
int plan[101][101];


int main()
{
    is >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            is >> plan[i][j];


    is.close();
    os.close();
    return 0;
}

void Schimbare(int x)
{
    for(int i = 1; i <= m; ++i)
    {
        if(b[i][x] == 0)
            b[i][x] = 1;
        else if(b[i][x] == 1)
            b[i][x] = 0;
    }
}
