#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is("vect.in");
ofstream os("vect.out");

vector<string> v1;
string s;

int main()
{
    while ( is >> s )
        v1.push_back(s);

    vector<string> v2(v1.begin() + 1, v1.begin() + 4);

    vector<string>::iterator it;
    for ( it = v2.begin(); it != v2.end(); ++it )
        os << *it << ' ';

    is.close();
    os.close();
    return 0;
}
