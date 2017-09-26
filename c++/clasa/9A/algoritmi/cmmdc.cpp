#include<fstream>
using namespace std;

ifstream is ("cmmdc.in");
ofstream os ("cmmdc.out");

int cmmdc(int a, int b);


int main()
{
    int x, y;

    is >> x >> y;
    int z = cmmdc(x, y);
    os << z;

    is.close ();
    os.close ();
    return 0;

}
int cmmdc(int a, int b)
{
    if ( a == 0)
        return b;
    if ( b == 0)
        return a;
    while (a != b)
        if ( a < b)
            b -= a;
        if (a > b)
            a -= b;
}
