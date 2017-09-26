#include <fstream>
using namespace std;
ifstream is("1.in");
ofstream os("1.out");

int main()
{
    int n, m;
    is >> n >> m;
    int a[3][4];
    for (int i = 0; i < n; i++)
        for (int j= 0; j < m; j++)
            is >> a[i][j];

    int aux;

    for (int j = 0; j < m; j++)
    {
        aux = a[0][j];
        for(int x = 1; x < n; x++)
            a[x - 1][j] = a[x][j];
        a[n-1][j] = aux;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < m; j++)
            os << a[i][j] << " ";
        os << '\n';
    }
    is.close();
    os.close();
    return 0;
}
