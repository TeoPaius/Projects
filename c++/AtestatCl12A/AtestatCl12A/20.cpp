#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int main()
{
    int a, b;
    int cnt[10] = {0};
    is >> a >> b;
    while(a)
    {
        cnt[a%10]++;
        a/=10;
    }
    while(b)
    {
        cnt[b%10]++;
        b/=10;
    }
    for(int i = 1; i <= 9; ++i)
    {
        if(cnt[i] > 0)
        {
            while(cnt[i])
            {
                os << i;
                cnt[i]--;
            }
        }
    }
    is.close();
    os.close();
    return 0;
}

