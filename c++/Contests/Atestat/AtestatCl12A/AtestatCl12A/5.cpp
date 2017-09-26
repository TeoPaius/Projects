#include <fstream>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

void Read(int& n, int a[100][100]);
int sub(int n, int a[100][100], int k);

int main()
{
    int n, a[100][100];
    Read(n, a);
    int x = 0;
    for ( int i = 2; i <= n; ++i)
        x = x + sub(n, a, i);
    os << x;
    is.close();
    os.close();
    return 0;
}

void Read(int& n, int a[100][100])
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            is >> a[i][j];

}

int sub(int n, int a[100][100], int k)
{
    int Suma = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if(i + j == k)
                Suma += a[i][j];
        }
    return Suma;
}
