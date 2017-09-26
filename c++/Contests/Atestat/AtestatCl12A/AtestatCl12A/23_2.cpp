#include <fstream>
using namespace std;

ifstream is("test.in");
ofstream os("test.out");


int main()
{
    int n;
    is >> n;
    int unul = 9;
    int doi = 180;
    int trei = 603;
    int volum = 792;
    int vol_complet = n / volum;
    bool ok = false;
    int nrpag = n - vol_complet*volum;

    if(nrpag <= 9)
    {
            os << vol_complet+1 << '\n';
            os << nrpag;
            ok = true;
    }
    else
    if(nrpag > 9)
    {
        nrpag -= 9;
        if(nrpag > 180)
        {
            nrpag -= 180;
            if(nrpag % 3 == 0)
            {
                nrpag /= 3;
                int pagina = 100+nrpag-1;
                os << vol_complet+1 << '\n';
                os << pagina;
                ok = true;
            }
        }
        else
        if(nrpag <= 180)
        {
            if(nrpag % 2 == 0)
            {
                nrpag /= 2;
                int pagina = 10 + nrpag-1;
                os << vol_complet+1 << '\n';
                os << pagina;
                ok = true;
            }
        }
    }
    if(ok == false)
    {
        os << "IMPOSIBIL";
    }
    is.close();
    os.close();
    return 0;
}
