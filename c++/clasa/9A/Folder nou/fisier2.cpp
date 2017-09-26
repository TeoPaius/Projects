#include <fstream>
using namespace std;

int main()
{
    ifstream is ("suma.in");
    ofstream os ("suma.out");
    int x , y ;
    is >> x;
    is >> y;
    os << x +y;
    os.close();
    is.close();
    return 0;


}
