#include <fstream>
#include <queue>
using namespace std;
ifstream is("teatru.in");
ofstream os("teatru.out");

int n;
char a[55000];
int c;
int st = 1, dr = 0;

int smax;
int s;
int nrc;
int p[100];
int S;



int main()
{
    is >> n >> c;
    for(int i = 1; i <= n; ++i)
        is >> a[i];
    while(dr <= n)
    {

        if(nrc <= c)
        {
            dr++;
            if(p[a[dr]] != 0)
            {
                p[a[dr]]++;
            }
            else
            {
                p[a[dr]]++;
                nrc++;
            }
        }

        else
        {
            s = dr - st;
            if(s > smax)
            {
                smax = s;
                S = st;
            }
            while(nrc > c)
            {
                p[a[st]]--;
                if(p[a[st]] == 0)
                    nrc--;
                st++;
            }
        }

    }
    os << smax << '\n';
    for(int i = S; i <= S + smax-1; ++i)
        os << a[i];

    is.close();
    os.close();
    return 0;
}

