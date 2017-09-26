#include <fstream>
using namespace std;
ifstream is ("fractii.in");
ofstream os ("fractii.out");

long n;
int Cmmdc(int a, int b);

int main()
{
    is >> n;
    long s = 0;

    for(int i = 2; i <= n; ++i)
    {
        s+= (n - i)/i;
    }
    os << s;
}

int Cmmdc(int a, int b)
{

    while(a =! b || a =! 1 || b =! 1)
    {
        if (a > b)
            a -= b;
        if (b > a)
            b -= a;
        if(a == 1)
            return a;
        if(b == 1)
            return b;

    }
    return a;

}
