#include<fstream>
using namespace std;

ifstream is ("cifre.in");
ofstream os("cifre.out");

int main()
{
    int n, a = 0, i, x, maxim = -1;
    is >> n;
    while ( n != 0)
    {   x = n % 10;
        if(x > maxim)
        {
            maxim = x;
            a = 1;
        }
        else
            if (x == maxim)
        {
            ++a;
        }
        n /= 10;
    }
    os << maxim << ' ';
    os << a;
    is.close();
    os.close();
    return 0;
}
