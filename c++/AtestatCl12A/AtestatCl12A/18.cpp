#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

int main()
{
    int n, m, a[101], b[101];
    is >> n >> m;
    for(int i = 1; i <= n; ++i)
        is >> a[i];
    for(int i = 1; i <= m; ++i)
        is >> b[i];

    int i = 1, j = 1;

    while(i <= n || j <= m)
    {
        if (i <= n && j <= m)
        {
            if (a[i] == b[j])
            {
                os << a[i] << " ";
                i++, j++;
            }
            else
            {
                if (a[i] < b[j])
                {
                    os << a[i] << " ";
                    i++;
                }
                else
                {
                    os << b[j] << " ";
                    j++;
                }
            }
        }
        else
        {
            if (i <= n)
            {
                os << a[i] << " ";
                i++;
            }
            else
            {
                os << b[j] << " ";
                j++;
            }

        }
    }

    is.close();
    os.close();
    return 0;
}
