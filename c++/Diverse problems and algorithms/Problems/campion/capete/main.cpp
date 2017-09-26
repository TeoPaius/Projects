#include <fstream>
using namespace std;
ifstream is("capete.in");
ofstream os("capete.out");

int main()
{
    int n, c;
    is >> n;
    c = n * 5;
    os << c;
    is.close();
    os.close();
    return 0;

}
