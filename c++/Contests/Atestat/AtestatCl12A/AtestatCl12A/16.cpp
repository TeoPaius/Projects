#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

int Base10(int x, int b);

int main()
{
    int b1, b2, x, y;
    is >> b1 >> b2 >> x >> y;
    os << Base10(x, b1) + Base10(y, b2);

    is.close();
    os.close();
    return 0;
}
int Base10(int x, int b)
{
    int nr = 0, f = 1;
    while(x)
    {
        nr += f * (x % 10);
        f *= b;
        x /= 10;
    }
    return nr;
}
