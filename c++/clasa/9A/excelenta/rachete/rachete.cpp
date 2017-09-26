#include<fstream>
using namespace std;

ifstream is("rachete.in");
ofstream os("rachete.out");

int main()
{
    int n, a = 0, g = 0, r = 0, x;
    is >> n;

    for (int i; i < n ; ++i)
    {
        is >> x;
        if ( x == 1)
            a++;
        if ( x == 2)
            g++;
        if ( x == 3)
            r++;
    }
    for (int i =0; i < a; ++i)
        os << 1 << ' ';
    for (int i = 0; i < g; ++i)
        os << 2 << ' ';
    for (int i = 0; i < r; ++i)
        os << 3 << ' ';

    is.close();
    os.close();
    return 0;

}

