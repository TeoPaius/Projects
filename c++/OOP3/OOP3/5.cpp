#include <fstream>
#include <vector>
using namespace std;

ifstream is("vect1.in");
ofstream os("vect1.out");

vector<int> v; // vector<int>()

int main()
{
    int x, n;
    is >> n;
    v.resize(n, 100);

    for ( int i = 0; i < v.size(); ++i )
        os << v[i] << ' ';
    is.close();
    os.close();
    return 0;
}
