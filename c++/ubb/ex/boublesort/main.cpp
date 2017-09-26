#include <fstream>
using namespace std;
ifstream is("1.in");
ofstream os("1.out");

int a[100];
int n;

void bsort(int a[100]);

int main()
{
    is >> n;
    for(int i = 1;i <= n; ++i)
        is >> a[i];

    bsort(a);

    for(int i = 1;i <= n; ++i)
    {
        os << a[i] << ' ';
    }

    is.close();
    os.close();
    return 0;
}

void bsort(int a[100])
{
    bool ok = false;
    int aux;
    while(!ok)
    {
        ok = true;
        for(int i = 1; i <= n - 1; ++i)
        {
            if(a[i] > a[i+1])
            {
                ok = false;
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
            }
        }
    }

}
