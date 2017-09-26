#include <fstream>
using namespace std;

ifstream is ("fprimi.in");
ofstream os ("fprimi.out");


int main ()
{
    int n, x, factor, aux, fp = 0, fpmax = 0, nmax = 0;
    is >> n;
    for(int i = 1; i <= n; i++)
    {
        is >> x;
        aux = x;
        factor = 2;
        fp = 0;
        while(aux != 1)
        {
            if(aux % factor == 0)
            {
            while(aux % factor == 0)
                aux /= factor;
            fp++;
            }
            if(factor == 2)
                factor++;
            else if(factor > 2)
                factor += 2;
        }
        if(fp > fpmax)
        {

            fpmax = fp;
            nmax = x;
        }
        else if (fp = fpmax && x < nmax)
        {
            if (x > nmax)
            nmax = x;
        }
    }
    os << nmax;

    is.close();
    os.close();
    return 0;
}


