#include <fstream>
using namespace std;
int x, n, s = 0;

int main()
{
    ifstream is("program.in");
    ofstream os("numere.out");

    is >> n;
    for ( int i = 0; i < n; i++)
    {
        is >> x;
        s += x;
    }

    os << s;

    os.close();
    is.close();
    return 0;
}
