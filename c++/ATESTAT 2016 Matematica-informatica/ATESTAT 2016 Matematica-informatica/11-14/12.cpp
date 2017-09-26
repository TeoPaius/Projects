#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

bool Prim(int x);

int main()
{
    int n;
    int a[100];

    is >> n;

    for(int i = 1; i <= n; ++i)
    {
        is >> a[i];
        if(Prim(a[i]))
            os << a[i] << ' ';
    }
    return 0;
}

bool Prim(int x)
{
    int d = 3;
    if(x == 1 || x == 0)
        return false;
    if(x == 2)
        return true;
    if(x % 2 == 0)
        return false;
    while(d*d <= x)
    {
        if(x % d == 0)
            return false;
        d+=2;
    }
    return true;


}
