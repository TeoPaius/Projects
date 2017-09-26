#include <fstream>
using namespace std;
ifstream is("1.in");
ofstream os("1.out");

int n, G;
int v[100], g[100];
int s[100];
int maxv, maxg;
int t[100];

void Write(int f);

int main()
{
    is >> n >> G;
    for(int i = 1; i <= n; ++i)
        is >> g[i];
    for(int i = 1; i <= n; ++i)
        is >> v[i];
    for(int i = 1; i <= G; ++i)
        s[i] = -1;
    s[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = G - g[i]; j >= 0; --j)
        {
            if(s[j] != -1)
                if(s[j+g[i]] < s[j] + v[i])
                {
                    s[j+g[i]] = s[j] + v[i];
                    t[j+g[i]] = g[i];
                    if(s[j] + v[i] > maxv)
                    {
                        maxv = s[j] + v[i];
                        maxg = j + g[i];
                    }

                }
        }

    os << maxv << '\n';
    os << maxg << '\n';
    Write(maxg);

    is.close();
    os.close();
    return 0;
}

void Write(int f)
{
    if(f == 0)
        return;
    os << t[f] << ' ';
    f -= t[f];
    Write(f);
}
