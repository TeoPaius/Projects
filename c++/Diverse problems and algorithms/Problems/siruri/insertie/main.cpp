#include <fstream>
using namespace std;
ifstream is("insertie.in");
ofstream os("insertie.out");

int main()
{
    int n, i, j, aux, ok;
    is >> n;
    int a[6];
    for(i = 0; i < n; ++i)
        is >> a[i];
    for(i = 1; i < n; ++i)
    {
        aux = a[i];
        ok = 0;
        j = i - 1;
        while(j >= 0 && !ok)
        {
            if(aux < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                ok = 1;
        }
        a[j + 1] = aux;
    }
    for (i = 0; i < n; ++i)
        os << a[i] <<' ';

    is.close();
    os.close();
    return 0;
}
