#include<fstream>
#include<cstring>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");

char nr[] = "0123456789";
char s[501];

int main()
{
    is.getline(s, 500, EOF);
    int n = strlen(s);
    int cnt = 0;
    bool ok= false;
    for(int i = 0; i < n; ++i)
    {

        if(strchr(nr, s[i]))
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if(cnt == 13)
        {
            ok = true;
            for(int j = i-13; j <= i; ++j)
            {
                os << s[j];
            }
            os << "\n";
            cnt = 0;
        }
        //os << s[i] << ' ' << cnt << '\n';
    }
    if(!ok)
    {
        os << 0;
    }
    is.close();
    os.close();
    return 0;
}
