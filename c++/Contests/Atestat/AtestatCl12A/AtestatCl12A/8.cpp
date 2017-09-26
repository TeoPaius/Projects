#include<fstream>
#define eps 0.001
using namespace std;


ifstream is("test.in");
ofstream os("test.out");

int main()
{
    int n;
    is >> n;
    double x;
    double a[100];
    for(int i = 1; i <= n; ++i)
    {
        is >> x;
        a[i] = x;
    }
    double aa = a[1];
    double bb = a[n];
    double aux;
    if(aa > bb)
    {
        aux = aa;
        aa = bb;
        bb = aux;
    }
    int cnt = 0;
    for(int i = 2; i <= n-1; i++)
    {
        if(a[i] < aa || a[i] > bb)
        {
            cnt++;
        }

    }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
