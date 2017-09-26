#include <iostream>
using namespace std;

int main()
{
    int *a;
    int n;
    cin >> n;
    a = new int[n];
    for ( int i = 0; i < n; ++i )
        a[i] = i + 1;

    for ( int i = 0; i < n; ++i )
        cout << a[i] << ' ';
   // delete a;// Memory Leak!
               // Se sterge doar a[0];
    delete [] a;
    return 0;
}
