#include <fstream>
using namespace std;
ifstream is ("1.in");
ofstream os ("1.out");

int main()
{
    int n;
    int x[100][100];
    is >> n;
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            is >> x[i][j];
            if (i > j)
                s1 += x[i][j];
            else if (j > i)
                s2 += x[i][j];
        }
    while (s1 != s2)
    {
        if (s1 > s2)
            s1 -= s2;
        else if (s2 > s1)
            s2 -= s1;
    }
    os << s1;
    return 0;
}
