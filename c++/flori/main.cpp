#include <fstream>
using namespace std;
ifstream is("flori.in");
ofstream os("flori.out");

int a[150][100];
int flori[100][150];
int grupe[150][150];
int maxim = 0;
bool gasit[150];
  int n, k;
int elemente_comune(int l1,int l2);
void grupare_linii(int l1, int l2);
void adauga_grupa_din_linia(int o);
int main()
{

    is >> n;
    is >> k;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
        {
            is >> a[i][j];
            if(a[i][j] > maxim)
                maxim = a[i][j];
            flori[a[i][j]][i] =  i;
        }


    for (int y=1;y<=n;y++)
    grupe[1][y]=flori[1][y];
    int jj;
    for(int i = 2; i <= maxim; ++i)
    {int f=0;
        for (jj=i-1;jj>=1;jj--)
        {
        f=elemente_comune(i,jj);
        if (f)
            {
            grupare_linii(i,jj);
            break;
            }
        }
        if (!f)
            adauga_grupa_din_linia(i);

    }

    bool pus = false;
    for(int i = 1; i <= n; ++i)
    {
         pus = false;
        for(int j = 1; j <= n; ++j)
        {

            if(grupe[i][j])
            {
                os << grupe[i][j] << ' ';
                pus = true;
            }
        }

if (pus)
            os << '\n';
    }
    is.close();
    os.close();
    return 0;

}
int elemente_comune(int l1,int l2)
{int element;
    for (int i=1; i<=n;i++)
        {int element=flori[l2][i];
         if (element)
            for (int j=1;j<=n;j++)
            if (element==flori[l1][j])
                return j;
        }
    return 0;
}
void grupare_linii(int l1, int l2)
{int primul=0;
 int comun=0;
    for (int i=1;i<=n;i++)
        {if (flori[l1][i]!=0 || flori[l2][i]!=0)
            {if (flori[l1][i]!=0)
                comun=flori[l1][i];
                else
                comun=flori[l2][i];
            }
            if (!primul)
                primul=comun;
                else
                grupe[primul][comun]=comun;
        }
}
void adauga_grupa_din_linia(int o)
{
int primul=0;
for (int i=1;i<=n;i++)
  {
    if(flori[o][i]!=0)
    if (primul==0)
    {
        primul=flori[o][i];
        grupe[primul][primul]=primul;
    }
        else
            grupe[primul][i]=i;
  }
}
