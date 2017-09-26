#include <fstream>
#include <cmath>
using namespace std;

ifstream is ("suma.in");
ofstream os ("suma.out");

long n;

int main()
{
    is >> n;
    int aux = n;
    int cnt = 0;
    int nr_zero;

    os << 1;
    if(n != 1)
    {

        while (aux > 9)
        {
            cnt++;
            aux -= 9;
        }
        nr_zero = n - cnt - 2;
        while(nr_zero)
        {
            os << 0;
            --nr_zero;
        }
        if(aux > 0)
        os << aux - 1;
        else
        os << aux;
        while(cnt)
        {
            os << 9;
            --cnt;
        }
    }

    os << '\n';

    if(n == 1)
        os << 1;
    else
    {
    aux = n;
    cnt = 0;
    while (aux >= 9)
    {
        os << 9;
        cnt++;
        aux -= 9;
    }
    os << aux;
    nr_zero = n - cnt - 1;
    while(nr_zero)
    {
        os << 0;
        --nr_zero;
    }

    }

    is.close();
    os.close();
    return 0;
}
