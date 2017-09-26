#include <fstream>
using namespace std;

ifstream is("colier.in");
ofstream os("colier.out");

int n, k;
int colier[1001];
int cnt = 1;
int cntmax = -1;

int main()
{
    is >> n;
    is >> k;

    int aux = k;
    while(aux != 0)
    {
        is >> colier[n - aux + 1];
        aux--;
    }
    for(int i = 1; i <= n - k; ++i)
        is >> colier[i];

    for(int i = 1; i <= n; ++i)
    {
        if(colier[i] == colier[i - 1])
            cnt++;
        if(colier[i] != colier[i - 1])
        {
            if(cnt > cntmax)
                cntmax = cnt;
            cnt = 1;
        }

    }
    os << cntmax;




    is.close();
    os.close();
    return 0;
}
