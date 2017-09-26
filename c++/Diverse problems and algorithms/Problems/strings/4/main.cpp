#include <fstream>
#include <cstring>
using namespace std;
ifstream is("4.in");
ofstream os("4.out");

char s[100];

int main()
{
    is.getline(s, 100, EOF);
    os << s;
    for(int i = strlen(s)-2; i >= 0; i--)
    {
        s[i] = 0;
        os << s << '\n';

    }
    is.close();
    os.close();
    return 0;
}
