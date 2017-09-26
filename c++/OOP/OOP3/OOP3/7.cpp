#include <fstream>
#include <vector>
using namespace std;

ifstream is("vect1.in");
ofstream os("vect1.out");

vector<int> v1(10); // construiesc un vector cu 10 elem de tip int
                   // care au val 0
vector<string> v2(7, "Daniel");
vector<string> v3 = v2; // copy constructor
int main()
{
    for ( int i = 0; i < v1.size(); ++i )
        os << v1[i] << ' ';

    os << '\n';
    for ( vector<string>::iterator it = v3.begin(); it != v3.end(); ++it )
        os << *it << ' ';


    is.close();
    os.close();
    return 0;
}
