#include <fstream>
#include <cmath>
using namespace std;
ifstream is("reg.in");
ofstream os("reg.out");

int n, m;
int a[100];
int sol;

void Back(int c, int x);
bool Ok(int l, int c);
void Write();

int main()
{
    is >> n >> m;
    Back(1, 0);
    os << sol;

    is.close();
    os.close();
    return 0;
}

void Back(int c, int x)
{

    if(x == m )
    {
        sol++;
        Write();
        return;
    }
    if(c > n)
    {
        return;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(Ok(i, c))
        {
            a[c] = i;
            Back(c+1, x+1);
            a[c] = 0;
        }
        //if(i == n)
           // Back(c+1, x);
    }
    Back(c+1, x);
}

bool Ok(int l, int c)
{
    for(int i = 1; i < c; ++i)
    {
        if(a[i] != 0)
        {
            if(a[i] == l)
                return false;
            if(abs(c - i) + 1 == abs(l - a[i]) + 1)
                return false;
        }
    }
    return true;
}

void Write()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(a[j] == i)
                os << 'R' << ' ';
            else
                os << '*' << ' ';

        }
        os << '\n';
    }
    os << '\n';
}
