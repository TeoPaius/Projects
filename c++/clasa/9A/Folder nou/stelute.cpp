#include<fstream>
using namespace std;

int main ()
{
    ifstream is("stelute.in");
    ofstream os("stelute.out");
    int n , c , l , i;
    l = 1;
    is >> n;
    while( l <= n )
    {   c = 1;
        while( c <= n ) // while ( c <= l )
        {
            os << "*  ";
            c++;
        }
        os << '\n';
        l++;
    }
    is.close();
    os.close();
    return 0;

}

