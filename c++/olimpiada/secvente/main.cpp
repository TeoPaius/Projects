#include <fstream>
using namespace std;
ifstream is("secvente.in");
ofstream os("secvente.out");

int main()
{
    int n, S, suma, k;
    is >> n;
    is >> S;
    int a[n];
    int b[S];
    for(int i = 0; i < n; ++i)
        is >> a[i];
    for(int i = 0; i < n; ++i)
    {
        suma = a[i];
        k = 0;
        for(int y = 0; y < S; ++y)
            b[y] = 0;
        for(int j = i + 1; j < n; ++j)
        {
            suma = suma + a[j];
            if(suma > S)
                break;
            else
            {
                b[k] = a[j];
                k++;
            }
            if(suma == S)
            {
                os << a[i] << " ";
                for(int y = 0; y < S; ++y)
                    if(b[y])
                        os << b[y] << ' ';
                os <<'\n';
            }

        }
    }
    return 0;
    is.close();
    os.close();
}
