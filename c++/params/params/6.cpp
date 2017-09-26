#include <iostream>
using namespace std;

/*
    a[i] = *(a + i) = *(i + a) = i[a]
*/
int main()
{
    int a[] = { 10, 20, 30, 40 };
    for ( int i = 0; i < 4; ++i )
        cout << i[a] << ' ';

    return 0;
}
