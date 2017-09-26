#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

vector<string> s;

int main()
{
    string cuv;
    while( is >> cuv )
        s.push_back(cuv);
    sort(s.begin(), s.end());

    for( const auto& c : s )
        os << c << '\n';

    is.close();
    os.close();
    return 0;
}

