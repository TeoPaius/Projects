#include <iostream>
using namespace std;

int main()
{
    int a[] = { 10, 20, 30, 40 };
    for ( int i = 0; i < 4; ++i )
        cout << *(a + i) << '\n';

    return 0;
}
