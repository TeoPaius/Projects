#include<fstream>
using namespace std;

ifstream is("baschet.in");
ofstream os("baschet.out");

int main()
{
    int n, x , a , lmax = 0;
    int y;
    int l = 0 ;
    is >> n;
    for (int i =0; i < n; ++i)
    {
        is >> x;
        if (i==0)
        {
            a = x;
            lmax = 1;
            y = x;
        }
        else
        {
           if (x == a)
            {
                l++;
                if (l > lmax )
                    {
                        lmax=l;
                        y=x;
                    }
            }
           else
            {
                l=1;
            }
        }
        a = x;
    }
    os << lmax << ' ' << y * lmax;
    is.close();
    os.close();
    return 0 ;
}
