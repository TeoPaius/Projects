#include<fstream>
using namespace std;

ifstream is("nrprime.in");
ofstream os("nrprime.out");

int main()
{
    int n, p = 2, exp = 0;
    is >> n;
    while(n != 1)
    {
        exp = 0;
        while(n % p == 0)
        {
            n /= p;
            ++exp;
        }
        if(exp)
            os << p << "^" << exp << ' ';
        if(p == 2)
            ++p;
        else
            p += 2;
    }
    is.close();
    os.close();
    return 0;
}
