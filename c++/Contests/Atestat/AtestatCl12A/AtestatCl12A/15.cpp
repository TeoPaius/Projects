#include <fstream>
using namespace std;
ifstream is ("test.in");
ofstream os ("test.out");

int main()
{
    int a, b, cif[10] = {0};
    is >> a >> b;

    while(a)
    {
        cif[a%10]++;
        a /= 10;
        n++;
    }
    while(b)
    {
        cif[b%10]++;
        b /= 10;
        n++;
    }

    for(int i = 9; i >= 0; --i)
    {
        while(cif[i])
        {
            os << i;
            cif[i]--;
        }
    }

    is.close();
    os.close();
    return 0;
}
