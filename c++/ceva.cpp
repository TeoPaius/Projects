#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int lin = 1;
    while(lin <= n)
    {
        int col = 1;
        while(col <= lin)
        {
            cout << "*";
            col++;
        }
        cout << '\n';
        lin++;
    }
    return 0;
}
