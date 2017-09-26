#include <fstream>
#include <cmath>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

bool test_fibo(int x);

int main()
{
    int n;
    int p[100];

    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> p[i];
        if(test_fibo(p[i]))
            os << p[i] << ' ';
    }

    // e gresit out-ul de pe subiect, nu contine 13

    return 0;
}

bool test_fibo(int x)
{
    double aux = 5 * x * x + 4;
    if((int)sqrt(aux) * (int)sqrt(aux) == (int)aux)
        return true;
    aux -= 8;
    if((int)sqrt(aux) * (int)sqrt(aux) == (int)aux)
        return true;
    return false;
}
