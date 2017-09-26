#include <fstream>
using namespace std;

ifstream is("flori1.in");
ofstream os("flori1.out");

int main()
{
    int n, S = 0, h, a[4], aux, K = 1;
    is >> n;
    is >> h;
    for(int i = 0; i < n; ++i)
     {
        is >> a[i];
        S += a[i];
     }
     do
     {
      for(int i = 0; i < n - 1; ++i)
            for(int j = i + 1; j < n; ++j)
                if(a[i] > a[j])
                {
                    aux = a[i];
                    a[i] = a[j];
                    a[j] = aux;
                }
            for (int x = 0;x < K;++x)
                a[x] = a[x] + 1;
            S += K;
            ++K;
    }while(a[n-1] < h);
    K-=2;
    os << S <<'\n';
    os << K;
    is.close();
    os.close();
    return 0;
}
