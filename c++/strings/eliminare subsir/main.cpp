#include <fstream>
#include <cstring>
using namespace std;
ifstream is("1.in");
ofstream os("1.out");


char s[10000];
char cuv[10000];
char* p;
int cnt;
int main()
{
    is.getline(s, 100);
    is.getline(cuv, 100);

    cnt = strlen(cuv);
    p = s;
    while(true)
    {
        p = strstr(p, cuv) + cnt;
        strcpy(p-cnt,p);
        if(!strstr(p, cuv))
            break;
    }


    os << s;
    is.close();
    os.close();
    return 0;
}
