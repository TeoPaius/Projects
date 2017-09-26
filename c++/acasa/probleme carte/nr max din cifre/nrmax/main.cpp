#include <fstream>
using namespace std;

ifstream is ("nrmax.in");
ofstream os ("nrmax.out");

int main()
{
    int n, c, aux;
    is >> n;
    for(c = 9; c >= 0; --c )
    {
        aux = n;
        while(aux != 0)
        {
            if(aux % 10 == c)
                os << c;
            aux /= 10;
        }

    }

    is.close();
    os.close();
    return 0;
}

