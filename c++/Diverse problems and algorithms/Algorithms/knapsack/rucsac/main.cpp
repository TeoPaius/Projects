#include <fstream>
using namespace std;

ifstream is("rucsac.in");
ofstream os("rucsac.out");

int n, g;
int w[10000];
int p[10000];
int v[10000];
int main()
{
    is >> n >> g;
    v[0] = 1;
    for(int i = 1; i <= n; ++i)
        is >> w[i] >> p[i];
    for(int i = 1; i <= n; ++i)
        for(int j = g - w[i]; j >= 0; --j)
            if(v[j] && v[j] + p[i] > v[j+w[i]])
                v[j+w[i]] = v[j] + p[i];
    int maxim = 0;
    for(int i = 1; i <= n+g+1; ++i)
    {
        os << v[i] << ' ';
        if(v[i] > maxim)
            maxim = v[i];
    }
    os << '\n';
    os << maxim;

    is.close();
    os.close();
    return 0;
}
