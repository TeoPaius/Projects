#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");
void apcar( char s[], char c, int& p );

int main()
{
    char s[256], c;
    int p;
    int sumav = 0;
    is.get(s, 256);
    char voc[] = "AEIOU";
    int i = 0;
    while( i <= 4)
    {
        apcar(s, voc[i], p);
        sumav += p;
        ++i;
    }

    os << sumav;

    is.close();
    os.close();
    return 0;
}
void apcar( char s[], char c, int& p )
{
    p = 0;
    char *x = strchr(s, c);
    while( x != NULL )
    {
        x = strchr(x+1, c);
        ++p;
    }

}

