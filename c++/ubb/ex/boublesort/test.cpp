#include <iostream>
using namespace std;

void Sortare( int n,int a[]);



int main()
{
    int s[] = {6, 8, 1, 2, 4, 5, 18};
    int n = 7;
    cout << n;
    int y = n;


    cout << n << ' ';
    Sortare(n,s);
    cout << y;

    return 0;
}

void Sortare(int n,int a[])
{
    int aux = 0;

    bool ok = false;
    do
    {
        ok = false;
        for(int i = 0; i < 7; ++i)
        {
            if(a[i] > a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                ok = true;
            }
        }
    }while(!ok);
    cout << "asta e aux " << aux << '\n';
}
