#include <fstream>
#include <vector>
using namespace std;

ifstream is("vect1.in");
ofstream os("vect1.out");

vector<int> v1(10, 7);


int main()
{
    vector<int> v2(v1.begin(), v1.begin() + 2);
    vector<int>::iterator it;
    for ( it = v2.begin(); it != v2.end(); ++it )
        os << *it << ' ';

    int a[] = { 10, 20, 30, 40 };

    vector<int> v3(a + 1, a + 3);
    os << '\n';
    for ( it = v3.begin(); it != v3.end(); ++it )
        os << *it << ' ';

    is.close();
    os.close();
    return 0;
}
