#include<fstream>
using namespace std;

ifstream is("invers.in");
ofstream os("invers.out");

int a;

int main()
{
    int n, inv = 0;
    is >> n;
    while ( n )
    {
        inv = inv * 10 + n % 10;
        n /= 10;

    }

    os << inv;

    is.close();
    os.close();
    return 0;
}
