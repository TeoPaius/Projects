#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is("vect.in");
ofstream os("vect.out");

int main()
{
    // un vector vid
    vector<int> v;   // vector<int>()
    int n;
    is >> n;
    int x;
    for ( int i = 0; i < n; ++i  )
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
