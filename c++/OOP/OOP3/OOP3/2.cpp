#include <fstream>
#include <vector>
using namespace std;

ifstream is("vect1.in");
ofstream os("vect1.out");

int main()
{
    int x;
    vector<int> v1; // vector<int>()
    while ( is >> x )
        v1.push_back(x);

    for ( int i = 0; i < v1.size(); ++i )
        os << v1[i] << ' ';
    is.close();
    os.close();
    return 0;
}
