#include <fstream>
using namespace std;
ifstream is ("8.in");
ofstream os ("8.out");

void Citeste( int& n, int a[100]);
int Rest(int n, int k, int a[100]);
void Det(int n, int a[100], int& x, int& y);
void Scrie(int a[100], int x, int y);

int main()
{
    int n;
    int a[100];
    Citeste(n, a);

    int x, y;

    Det(n, a, x, y);

    is.close();
    os.close();
    return 0;
}

void Citeste( int& n, int a[100])
{
    is >> n;
    for(int i = 0; i < n; ++i)
        is >> a[i];
}

int Rest(int n, int k, int a[100])
{
    int s = 0;
    for(int i = 0; i <= k; ++i)
        s += a[i];
    return s % n;
}

void Det(int n, int a[100], int& x, int& y)
{
    for(int i = 0; i < n - 2; ++i)
    {
        for(int j = i + 2; j < n; ++j)
        {
            if(Rest(n, i , a) == Rest(n, j, a))
            {
                x = i;
                y = j;
                Scrie(a, x, y);
                os << '\n';
            }
        }
    }
}

void Scrie(int a[100], int x, int y)
{
    for(int i = x + 1; i <= y; ++i)
        os << a[i] << ' ';
}
