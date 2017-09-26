#include <fstream>
using namespace std;
ifstream is("paranteze.in");
ofstream os("paranteze.out");

int n;
int a[100];

void Back(int k, int pd);
bool Ok(int k , int pd);
void Write();

int main()
{
    is >> n;
    Back(1,0);
    is.close();
    os.close();
    return 0;
}

void Back(int k, int pd)
{
    if(k > 2 * n)
    {
        Write();
        return;
    }
    for(int i = 0; i <= 1; ++i)
    {
        if(Ok(k, pd + i))
        {
            a[k] = i;
            Back(k + 1, pd + i);
        }
    }
}

bool Ok(int k, int pd)
{
    if(pd < k - pd)
        return false;
    if(pd > n)
        return false;
    return true;
}

void Write()
{
    for(int i = 1; i <= 2 * n; ++i)
    {
        if(a[i] == 1)
            os << '(';
        else
            os << ')';
    }
    os << '\n';
}
