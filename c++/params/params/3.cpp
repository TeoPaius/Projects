#include <fstream>
using namespace std;

ifstream is("matrice.in");
ofstream os("matrice.out");

void Read(int a[100][200], int& m, int& n);
void Write(int a[100][200], int m, int n);

int main()
{
    int b[100][200], m, n; // var var locale

    Read(b, m, n);
    Write(b, m, n);

    is.close();
    os.close();
    return 0;
}

void Read(int a[100][200], int& m, int& k)
{
    is >> m >> k;
    for (int i = 0; i < m; ++i )
        for ( int j= 0; j < k; ++j )
        is >> a[i][j];
}

void Write(int a[100][200], int m, int n)
{
    for ( int i = 0; i < m; ++i )
    {
        for ( int j = 0; j < n; ++j )
            os << a[i][j] << ' ';
        os << '\n';
    }
}
