#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int main()
{
    int s[100]={0}, x, maxim = 0, nr;
    while(is >> x)
    {
        s[x]++;
        if(s[x] > maxim)
        {
            maxim = s[x];
            nr = x;
        }
    }
    os << nr;
    is.close();
    os.close();
    return 0;
}
