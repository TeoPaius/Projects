#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream is ("nrtri.in");
ofstream os ("nrtri.out");

int n;
vector<int> a;
int Ok(int st);
int suma;
int cnt;

int main()
{
    is >> n;
    a.push_back(0);
    for(int i = 1; i <= n; ++i)
    {
        int aux;
        is >> aux;
        a.push_back(aux);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= n - 2; ++i)
        for(int j = i + 1; j <= n - 1; ++j)
        {
            suma = a[i] + a[j];
            cnt += Ok(j) - j - 1;
        }
    os << cnt;
    is.close();
    os.close();
    return 0;
}
int Ok(int st)
{
    int m;
    int dr = n;
    while(st < dr)
    {
        m = (st + dr) / 2;
        if(a[m] > suma)
            dr = m - 1;
        else
            st = m + 1;
    }
    if(suma >= a[dr])
        dr += 1;
    return dr;
}
