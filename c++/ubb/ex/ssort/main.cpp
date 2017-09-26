#include <iostream>

using namespace std;

int a[100];
int n;

void Selsort(int a[100]);

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    Selsort(a);
     for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}

void Selsort(int a[100])
{
    int minim;
    int minpos;
    int aux;
    for(int k = 1; k <= n; ++k)
    {
        minim = 0x3f3f3f3f;
        for(int i = k; i <= n; ++i)
        {
            if(minim > a[i])
            {
                minim = a[i];
                minpos = i;
            }
        }
        aux = a[k];
        a[k] = a[minpos];
        a[minpos] = aux;
    }
}
