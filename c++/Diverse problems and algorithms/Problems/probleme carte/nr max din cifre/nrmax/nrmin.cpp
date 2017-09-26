#include <fstream>
using namespace std;

ifstream is ("nrmax.in");
ofstream os ("nrmin.out");

int main()
{
    int n, c, aux, nrmin = 0;
    is >> n;
    for(c = 1; c <= 9; ++c )
    {
        aux = n;
        while(aux != 0)
        {
            if(aux % 10 == c)
                nrmin = nrmin * 10 + c;
            aux /= 10;
        }
    }
    os << nrmin;

    is.close();
    os.close();
    return 0;
}

