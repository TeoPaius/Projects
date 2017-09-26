#include <fstream>
using namespace std;
ifstream is("insertietest.in");
ofstream os("insertietest.out");

int main()
{
    int n, i, j, aux, a[100];
    bool ok;
    is >> n;
    for(i = 0; i < n; i++)
        is >> a[i];
    for(i = 1; i < n; ++i)
    {
        aux = a[i];
        ok = false;
        j = i - 1;
        while(j >= 0 && !ok)
        {
            if(a[j] > aux)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                ok = true;
        }
        a[j + 1] = aux;
    }

    for(i = 0; i < n; ++i)
        os << a[i] << " ";
    is.close();
    os.close();
    return 0;
}
