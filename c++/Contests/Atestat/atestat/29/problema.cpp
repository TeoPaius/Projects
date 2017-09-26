#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int i = 1, q = 1;
    while(i < n/i)
    {
        if(n % i == 0)
            q += i;
        i += 3;

    }
    cout << q;
    return 0;

}
