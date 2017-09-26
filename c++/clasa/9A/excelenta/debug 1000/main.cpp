#include<fstream>
using namespace std;

ifstream is("baschet.in");
ofstream os("baschet.out");

int main()
{
    int n, a, maxim = -99999;
    is >> n;
    for (int i = 0; i < n ; ++i)
    {
        is >> a;
        if (a > maxim)
        {
            maxim = a;
        }

    }
    os << a;

    is.close();
    os.close();
    return 0 ;
}
