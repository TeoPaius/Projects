#include <fstream>
#define INF 0x3f3f3f3f
using namespace std;

ifstream is("test.in");
ofstream os("test.out");


int Fibo(int fib[50], int n)
{
    int cnt;
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; fib[i-1] <= n; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
        cnt = i;
    }

    return cnt;
}
// 1 1 2 3 5 8 13

int Caut_Bin(int n, int fib[50], int cnt, int v)
{
    int st = 0;
    int dr = cnt;
    int mij = 0;
    int val = 0;
    while(st <= dr)
    {
        mij = (st + dr)/2;
        if(n == fib[mij] && n == v)
        {
            val = fib[mij-1];
            return val;
        }
        if(n < fib[mij])
        {
            dr = mij-1;
        }
        else
        {
            st = mij + 1;
            val = fib[mij];
        }
    }
    return val;
}


int main()
{
    int n;
    int fib[50] = {0};
    is >> n;
    int cnt;
    int cnt2 = 0;
    cnt = Fibo(fib, n);
    int dif = n;
    int rez[50] = {0};
    int val;
    val = Caut_Bin(dif, fib, cnt, n);
    while(dif != 0 && val != 0)
    {
        dif = dif - val;
        rez[cnt2] = val;
        cnt2++;
        val = Caut_Bin(dif, fib, cnt, n);
    }

    os << n << "= ";
    for(int i = 0; i < cnt2-1; ++i)
    {
        os << rez[i] << " + ";
    }
    os << rez[cnt2-1];

    is.close();
    os.close();
    return 0;

}
