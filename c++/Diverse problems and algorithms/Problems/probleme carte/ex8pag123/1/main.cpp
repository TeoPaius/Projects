#include <fstream>
using namespace std;

ifstream is ("1.in");
ofstream os ("1.out");
int Cmmdc (int a, int b);

int main()
{
    int x[100][100];
    int n;
    is >> n;
    int cmmdc, a, b;
    for(int i = 0; i < n; i++)
        for(int j = 0;j < n; j++)
            is >> x[i][j];

     for(int j = 0; j < n; j++)
     {
        cmmdc = x[0][j];
        for(int i = 1; i < n; i++)
        {
            cmmdc = Cmmdc(x[i][j], cmmdc);
        }
        os << cmmdc << " ";
     }
    is.close();
    os.close();
    return 0;
}

int Cmmdc (int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
