#include <fstream>
#include <climits>
using namespace std;

int main()
{
    ifstream is ("maxim.in");
    ofstream os ("maxim.out");
    int a , n , maxim = INT_MIN , nrap = 0;
    is >> n;
    int i = 1;
    while(i <= n)
    {
        is >> a;
        if(a > maxim)
        {
            maxim = a;
            nrap = 1;
        }
        else if ( maxim == a )
            nrap++;
        ++i;
    }

    os << " maxim este = " << maxim << ' ';
    os << " apare de " << nrap << " ori " << ' ';

    return 0;

    is.close ();
    os.close ();
}
