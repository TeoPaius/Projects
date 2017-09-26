#include <fstream>
using namespace std;
ifstream is("aib.in");
ofstream os("aib.out");

int n, o, q;
int a[100];
int ini[100];
int s;
int valu;
int pos;
int pos1, pos2;
int old;

void Update(int val, int pos);
int Sum(int pos);

int main()
{
    is >> n >> o;
    for(int i = 1; i <= n; ++i)
    {
        is >> valu;
        Update(valu,i);
    }

    for(int i = 1; i <= o; ++i)
    {
        is >> q;
        if(q == 0)
        {
            is >> valu;
            is >> pos;
            Update(valu, pos);
        }
        if(q == 1)
        {
            is >> pos;
            os << Sum(pos) << '\n';
        }
        if(q == 2)
        {
            is >> pos1 >> pos2;
            os << Sum(pos2) - Sum(pos1 - 1) << '\n';
        }
    }
    is.close();
    os.close();
    return 0;
}

void Update(int val, int pos)
{
    old = val - ini[pos];
    ini[pos] = val;
    for(int i = pos; i <= n; i += i & - i)
    {
        a[i] += old;
    }

}
int Sum(int pos)
{
    s = 0;
    for(int i = pos; i; i -= i & -i)
        s += a[i];
    return s;

}
