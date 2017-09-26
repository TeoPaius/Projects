#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is("vect.in");
ofstream os("vect.out");

int main()
{
    int a[] = { 10, 20, 30, 40, 50 };

    vector<int> v(a + 1, a + 4);
    vector<int>::iterator it;
    for ( it = v.begin(); it != v.end(); ++it )
        os << *it << ' ';

    is.close();
    os.close();
    return 0;
}
