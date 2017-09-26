#include <fstream>
#include <cstring>
using namespace std;
ifstream is("3.in");
ofstream os("3.out");

char s[100];

int main()
{
    is.getline(s,100,EOF);
    s[0] = toupper(s[0]);
    s[strlen(s)-2] = toupper(s[strlen(s)-2]);
    os << s;

    char a[] = "alexandru";
    a[2] = 0;
    os << a;
    os << a[3];
    is.close();
    os.close();
    return 0;
}
