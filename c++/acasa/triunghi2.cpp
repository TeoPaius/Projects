#include<fstream>
using namespace std;

int main()
{
    int n, l, c;
    ifstream is ("triunghi.in");
    ofstream os ("triunghi.out");
    is >> n;
    l = 1;
    while ( l <= n )
    {
        c = 1;
        while (c <= n)
        {
            if( c + l >= n + 1 )
            os << "* ";
            else{
            os << "  ";
            }
            c++;
        }
        os << '\n';
        l++;
    }
    is.close();
    os.close();
    return 0;
}
