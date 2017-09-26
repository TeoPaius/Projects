#include <fstream>
#include <cstring>
using namespace std;

ifstream is("2.in");
ofstream os("2.out");

int main()
{
    int n;
    char a[20];
    char b[20];
    int cnt = 0;
    is >> n;
    is.get();
    is.getline(a, 19);
    for ( int i = 0; i < n - 1; ++i )
    {
        is.getline(b, 19);
        if ( strstr(b + strlen(b) - strlen(a), a) != NULL )
            ++cnt;
    }
    os << cnt;

    is.close();
    os.close();
    return 0;
}
