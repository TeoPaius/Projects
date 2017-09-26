#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

ifstream is("date.in");
ofstream os("date.out");




int main()
{
    char s[255];
    char cuv[] = "ate";
    char sep[] = ",.;:!?";
    while( is >> s )
    {
        if( strstr(s, cuv) )
        {
            for( int i = 0; i < strlen(s); ++i )
                if(strchr(sep, s[i]))
                    continue;
                else
                    os << s[i];
            os << '\n';
        }
    }

    is.close();
    os.close();
    return 0;
}
