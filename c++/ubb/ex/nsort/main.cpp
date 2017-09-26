#include <iostream>

using namespace std;

int n;
int a[100];

void Isort(int a[100]);

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    Isort(a);
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}

void Isort(int a[100])
{
    int aux;
    for(int i = 2; i <= n; ++i)
    {
        int j = i-1;
        aux = a[i];
        while(aux < a[j] && j > 0)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = aux;
    }
}
