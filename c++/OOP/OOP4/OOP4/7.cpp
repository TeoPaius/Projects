#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream is("vect.in");
ofstream os("vect.out");

vector<string> v;
string s;

int main()
{
    while ( is >> s )
        v.push_back(s);

    vector<string>::iterator it;
    for ( it = v.begin(); it != v.end(); ++it )
        os << *it << ' ';

    is.close();
    os.close();
    return 0;
}
