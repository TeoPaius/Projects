#include <fstream>
using namespace std;

int main()
{
    ifstream is("program.in");
    ofstream os("program.out");


    int a, b;
    is >> a;
    is >> b;
    os << a + b;



    os.close();
    is.close();
    return 0;
}
