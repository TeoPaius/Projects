#include <fstream>
#include <stack>
using namespace std;
ifstream is ("transport.in");
ofstream os ("transport.out");

int n, k, cap, cnt;
int st;
int dr = 100000000;
int a[16001];
int m;

int main()
{
    is >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        is >> a[i];
        if (a[i] > st)
            st = a[i];
    }
    while(st < dr)
    {
        cnt = 1;
        cap = 0;


        m = (st + dr)/2;
        for(int i = 1; i <= n; ++i)
        {
            if(cap + a[i] <= m)
                cap += a[i];
            else
            {
                cap = a[i];
                cnt++;
            }
        }
        if(cnt > k)
            st = m + 1;
        else
            dr = m;


    }
    os << st;

    is.close();
    os.close();
    return 0;
}
