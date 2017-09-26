
#include <iostream>
using namespace std;

class Intreg {
    int n;
public:
    Intreg()
    {
        n = 0;
       // cout << "c-tor\n";
    }

    Intreg(int _n)
    {
        n = _n;
    }
    int GetN()
    {
        return n;
    }
};

int main()
{
    Intreg x; // obiect (intanta) a clasei
    cout << x.GetN() << '\n';

    Intreg y(100); // Apel Implicit Intreg(100)
    cout << y.GetN();
    Intreg z = Intreg(200); // Apel Explicit Intreg(100)

    return 0;
}

