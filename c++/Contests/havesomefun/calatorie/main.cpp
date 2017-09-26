#include <fstream>
#include <vector>
using namespace std;
ifstream is("calatorie.in");
ofstream os("calatorie.out");

int n, t;
vector<int> nk;
vectori<int> hk;


int main()
{
    is >> n;
    for(int xy = 1; xy <= n; ++xy)
    {
        is >> t;
        for(int yx = 1; yx <= t; ++yx)
        {
            int aux1, aux2;
            is >> aux1 >> aux2;
            nk.push_back(aux1);
            hk.push_back(aux2);

        }
        nk.clear();
        hk.clear();
    }
    is.close();
    os.close();
    return 0;
}
