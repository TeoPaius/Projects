#include <fstream>

using namespace std;

ifstream is("test.in");
ofstream os("test.out");

int main()
{
    int n, cifvol = 792;
    is >> n;
    int cnt = 0; // volume
    while( n >= cifvol )
    {
        ++cnt;
        n -= cifvol;
    }
    --cnt;
    int i = 1;
    bool pos = true;
    for( i = 1; i < 300 && pos && n > 0; ++i)
        {
            if( i < 10 )
            {
                if( n - 1 < 0 )
                    pos = false;
                n -=1;
            }
            if( i >= 10 && i <= 99 )
            {
                if( n - 2 < 0 )
                    pos = false;
                n -= 2;
            }
            if( i > 99 )
            {
                if( n - 3 < 0 )
                    pos = false;
                n -= 3;
            }
        }
    if( n == 0)
        ++cnt;

    if( pos )
    {
        os << cnt << '\n';
        if( i - 1 == 0 )
            os << 300;
        else
            os << i - 1;

    }
    else
        os << "IMPOSIBIL";

    return 0;
}

