#include <fstream>
using namespace std;
ifstream is ("sir.in");
ofstream os ("sir.out");


int main()
{
    int a, n5 = 0, m = 0, n7 = 0, maxim = 0;
    is >> a;
    int n[a];
    for(int i = 0; i < a; ++i)
    {
        is >> n[i];
        if (n[i] < 5)
            n5++;
        m = m + n[i];
        if (n[i] == 7)
            n7++;
        if (n[i] >= maxim)
            maxim = n[i];
    }
    os << "sunt " << n5 << " note mai mici ca 5" << '\n';
    os << "media aritmetica a notelor este " << m / a << '\n';
    os << "au fost obtinute " << n7 << " note de 7" << '\n';
    os << "cea mai mare nota este " << maxim;

    is.close();
    os.close();
    return 0;

}
