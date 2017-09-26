#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int **a = new int*[n + 1];
    for ( int i = 1; i <= n; ++i )
        a[i] = new int[n + 1];
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
            a[i][j] = j;
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= n; ++j )
            cout << a[i][j] << " ";
        cout << "\n";
    }
    for ( int i = 1; i <= n; ++i )
        delete[] a[i];
    delete[] a;
    return 0;
}
