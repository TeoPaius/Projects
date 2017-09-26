// Cod executat inainte de main
#include <iostream>
using namespace std;

class Test {
public:
    Test()
    {
        cout << "Construiesc aux\n";
    }
    ~Test()
    {
        cout << "Distrug aux\n";
    }
};

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        Test aux;
    }


    return 0;
}
