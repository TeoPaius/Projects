
#include <iostream>
using namespace std;

struct Test {
public:
    Test()
    {
        cout << "Construiesc obiect\n";
    }
    ~Test()
    {
        cout << "Distrug obiect\n";
    }
};
int main()
{
    for ( int i = 0; i < 10; ++i )
    {
        Test T;
    }

    return 0x0;
}


