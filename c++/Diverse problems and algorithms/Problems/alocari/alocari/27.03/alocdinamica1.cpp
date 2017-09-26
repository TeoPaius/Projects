#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int a[] = { 10, 20, 30, 40 };
    for ( int i = 0; i < n; ++i )
        cout << *(a + i) << ' ';
    cout << '\n';
    return 0;
}
