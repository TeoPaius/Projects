#include <fstream>
#include <cstring>
using namespace std;
ifstream is("2.in");
ofstream os("2.out");

char trg[100];
char re[100];
char s[100];
char final[100];
int cnt;
int aux;
char* p1;
char* p;
int main()
{
    is >> trg;
    is >> re;
    is.get();
    is.getline(s,100, EOF);
    cnt = strlen(trg);

    p = s;
    p1 = s;
    while(strstr(p, trg))
    {
        p = strstr(p, trg);
        aux = p - p1;
        strncat(final, p1, aux);
        strcat(final, re);
        p1 = p + cnt;
        p += cnt;
    }

    os << final;
    return 0;
    is.close();
    os.close();
}
