#include <fstream>
using namespace std;

ifstream is("numere.in");
ofstream os("numere.out");

void Mic(int x);
void Mare(int x);

long int n;

int main()
{

    is >> n;
    Mic(n);
    Mare(n);
    is.close();
    os.close();
    return 0;
}

void Mare(int x)
{
    bool ok = true;
    int a[10] = {0};
    while(x > 1 && ok)
    {
        ok = false;
        for(int i = 2; i <= 9; ++i)
            if(x % i == 0)
            {
                x /= i;
                a[i]++;
                ok = true;
                break;
            }
    }
    for(int i = 9; i >= 2; --i)
        while(a[i])
        {
            os << i;
            a[i]--;
        }
    os << ' ';

}

void Mic(int x)
{
    bool ok = true;
    int a[10] = {0};
    while(x > 1 && ok)
    {
        ok = false;
        for(int i = 9; i >= 2; --i)
            if(x % i == 0)
            {
                x /= i;
                a[i]++;
                ok = true;
                break;
            }
    }
    for(int i = 2; i <= 9; ++i)
        while (a[i])
        {
            os << i;
            a[i]--;
        }
    os <<' ';
}
