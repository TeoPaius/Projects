#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

int suma_cifre(int x);

int main()
{
    int n, x;
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> x;
        if (suma_cifre(x) % 3 == 0)
            os << x << " ";
    }
    is.close();
    os.close();
    return 0;
}

int suma_cifre(int x)
{
    int s = 0;
    while(x)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}
