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
    os << "vectorul are " << v.size() << " elemente\n";
    int x;
    while ( is >> x )
        v.push_back(x);
    os << "vectorul are " << v.size() << " elemente\n";

    for ( int i = 0; i < v.size(); ++i )
        os << v[i] << ' ';
    is.close();
    os.close();
    return 0;
}
