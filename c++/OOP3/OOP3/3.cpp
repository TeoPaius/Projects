#include <fstream>
#include <vector>
using namespace std;

ifstream is("vect1.in");
ofstream os("vect1.out");

int main()
{
    int x, n;
    vector<int> v; // vector<int>()
    is >> n;
    for ( int i = 0; i < n; ++i )
    {
        is >> x;
        v.push_back(x);
    }

    for ( int i = 0; i < v.size(); ++i )
        os << v[i] << ' ';
    is.close();
    os.close();
    return 0;
}
