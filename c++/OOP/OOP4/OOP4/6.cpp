#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is("vect.in");
ofstream os("vect.out");

int main()
{
    vector<float> v(100);
    vector<int> v1(20, -5);
    vector<string> v2(10, "Diana");

    for ( int i = 0; i < v2.size(); ++i )
        os << v2[i] << ' ';
    is.close();
    os.close();
    return 0;
}
