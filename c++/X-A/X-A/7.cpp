// Cod executat in inte de main
#include <iostream>
using namespace std;

class Test {
public:
    Test()
    {
        cout << "Cod care se executa inainte de main\n";
    }
};

Test c;

int main()
{
    cout << "Intrare in main()\n";
    return 0;
}
