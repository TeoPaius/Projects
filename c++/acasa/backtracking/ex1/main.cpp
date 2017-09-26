#include <fstream>
using namespace std;
ifstream is("back.in");
ofstream os("back.out");

int n;
int a[100];
int x[100];
bool s[100];
void Write(int k);
void Back(int k);
int nrsol;

int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
        is >> x[i];
    Back(1);
    os << nrsol;
    is.close();
    os.close();
    return 0;
}

void Back(int k)
{
    if(k > n)
    {
        Write(k - 1);
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        a[k] = i;
        if(!s[i])
        {
            s[i] = true;
            Back(k+1);
            s[i] = false;
        }

    }
}

void Write(int k)
{
    for(int i = 1; i <= k; ++i)
        os << a[i] << ' ';
    os << '\n';
}
