#include <fstream>
using namespace std;
ifstream is ("fractii.in");
ofstream os ("fractii.out");

long n;
int Cmmdc(int a, int b);
float suma(int);
int main()
{
    is >> n;
    float f=suma(n);
    os<< f;
   /* long cnt = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
        {
            if(Cmmdc (i, j) == 1)
                cnt += 2;
        }
    cnt += 1;
    os << cnt;
    */
    is.close();
    os.close();
    return 0;

}

int Cmmdc(int a, int b)
{

    while(a != b )
    {
        if (a > b)
            a -= b;
        if (b > a)
            b -= a;
        if(a == 1)
            return a;
        if(b == 1)
            return b;
    }
    return a;

}
float suma (int p)
{ float s=0;
    for (int i=1;i<=p;i++)
    s+=i;
    return s;
}
