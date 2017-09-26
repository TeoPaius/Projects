#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

ifstream is("date.in");
ofstream os("date.out");

char cuv[255];
int cnt;
char voc[] = "aeiou";
bool ok;

int main()
{
    while( is >> cuv )
    {
        cout << cuv << '\n';
        for( int i = 0; i < strlen(cuv); ++i )
            if( strchr(voc, cuv[i]) )
            {
                if( i )
                    if( strchr(voc, cuv[i-1]) )
                    {
                        ++cnt;
                        ok = true;
                    }
            }
    }
    if( ok )
        os << cnt << '\n';
    else
        os << "NU EXISTA\n";

    is.close();
    os.close();
    return 0;
}
