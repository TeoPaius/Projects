#include <iostream>
using namespace std;

/*
   b = a[i]
   a[i][j] = b[j] = *(b + j) = *(a[i] + j)
           = *(*(a + i) + j)
*/
int main()
{
    int a[2][3] = { {10, 20, 30},
                    {40, 50, 60} };
    for ( int i = 0; i < 2; ++i )
    {
        for ( int j = 0; j < 3; ++j )
            cout << *(*(a + i) + j) << ' ';
        cout << '\n';
    }

    return 0;
}
