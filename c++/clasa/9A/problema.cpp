#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a , n , maxim = INT_MIN , nrap = 0;
    cout << "n = "; cin >> n;
    int i = 1;
    while(i <= n)
    {
        cout << "a = "; cin >> a;
        if(a > maxim)
        {
            maxim = a;
            nrap = 1;
        }
        else if ( maxim == a )
            nrap++;
        ++i;
    }

    cout << " maxim = " << maxim << ' ';
    cout << " apare de " << nrap << " ori " << ' ';
    return 0;


}
