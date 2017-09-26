#include <fstream>
using namespace std;

ifstream is("numere.in");
ofstream os("numere.out");

int x, y;
long long sus;
long long jos = 1;
int a[2000], b[2000];

long long Cmmdc1 (long long a, long long b);
long long c;

int main()
{
    is >> x >> y;
    for(int i = 0; i < x; ++i)
    {
        is >> a[i];
        sus = sus * 10 + a[i];
    }
    for(int i = 0; i < y; ++i)
    {
        is >> b[i];
        sus = sus * 10 + b[i];
        jos *= 10;
    }
    c = Cmmdc1 (sus, jos);

    sus /= c;
    jos /= c;
    int cnt = 0;
    long long aux;
    aux = sus;
    while(aux)
    {
        cnt ++;
        aux /= 10;
    }
    os << cnt << '\n' << sus << '\n';

    cnt = 0;
    aux = jos;
    while(aux)
    {
        cnt ++;
        aux /= 10;
    }

    os << cnt << '\n' << jos;

    is.close();
    os.close();
    return 0;
}

long long Cmmdc1 (long long a, long long b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while( a != b)
    {
        if(a > b)
            a -= b;
        if(b > a)
            b -= a;
    }
    return a;
}
