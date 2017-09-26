#include <fstream>
using namespace std;

ifstream is ("printesa.in");
ofstream os ("printesa.out");
bool Prim(int a);

int main()
{
    int k, h, pret = 2, j = 0;
    is >> k >> h;
    bool ok;
    int ru[h];
    int pre[k];
    for (int i = 0; i < h; ++i)
        is >> ru[i];
    int kaux = k;
    while(k != 0)
    {
        if(Prim(pret))
        {
            ok = true;
            for(int i = 0; i < h; ++i)
            {
                if(pret == ru[i])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                k--;
                pre[j] = pret;
                j++;
            }
        }
        if(pret == 2)
            pret++;
        else
            pret += 2;
    }
    int aux;
    for(int i = 0; i < kaux - 1; ++i)
        for (int o = i + 1; o < kaux; ++o)
            if(pre[i] < pre[o])
            {
                aux = pre[i];
                pre[i] = pre [o];
                pre[o] = aux;
            }
    for(int i = 0; i < kaux; ++i)
        os << pre[i] << ' ';


    is.close();
    os.close();
    return 0;
}
bool Prim(int a)
{
    if (a == 0 || a == 1)
        return false;
    if (a == 2)
        return true;
    if (a % 2 == 0 )
        return false;
    for (int div = 3; div * div <= a; div += 2)
    {
        if(a % div == 0)
            return false;
    }
    return true;

}
