#include <fstream>
using namespace std;

ifstream is ("sir.in");
ofstream os ("sir.out");

long n;
int a;
int y=0;
int cnt = 0;
int aux;

int main()
{
    is >> n;
    int i = 1;
    while(i <= n)
    {
        cnt++;
        for(int j = 1; j <=cnt && i <= n; ++j)
            for(int h = 1; h <= cnt && i <= n; ++h)
            {
                a = j;
                ++i;
            }

        for(int j = 1; j <=cnt && i <= n; ++j)
            for(int h = 1; h <= cnt && i <= n; ++h)
            {
                a = -j;
                ++i;
            }

    }
    os << a;
    is.close();
    os.close();
    return 0;
}
