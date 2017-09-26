#include <fstream>
#include <cmath>
using namespace std;
ifstream is("triunghi.in");
ofstream os("triunghi.out");

double Arie(double x1, double x2, double x3);
double Latura(double x1, double y1, double x2, double y2);
bool Verificare(int x, int y);

struct Punct{
    int x;
    int y;
}tr[66][3];

int n;
int xf, yf;
int cnt;
int a[66];

double l3;
double l2;
double l1;
double su;
double xl1;
double xl2;
double xl3;
double af1;
double af2;
double af3;
double l1max;
double l2max;
double l3max;

double sumax = -1;
int imax = -1;


int main()
{
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 3; ++j)
        {
            is >> tr[i][j].x;
            is >> tr[i][j].y;
        }
    }
    is >> xf >> yf;


    for(int i = 1; i <= n; ++i)
    {

        l3 = Latura(tr[i][1].x, tr[i][1].y, tr[i][2].x, tr[i][2].y);
        l2 = Latura(tr[i][1].x, tr[i][1].y, tr[i][3].x, tr[i][3].y);
        l1 = Latura(tr[i][2].x, tr[i][2].y, tr[i][3].x, tr[i][3].y);
        su = Arie(l1, l2, l3);
        if(su > sumax)
        {
            imax = i;
            sumax = su;
            l1max = l1;
            l2max = l2;
            l3max = l3;
        }
        xl1 = Latura(tr[i][1].x, tr[i][1].y, xf, yf);
        xl2 = Latura(tr[i][2].x, tr[i][2].y, xf, yf);
        xl3 = Latura(tr[i][3].x, tr[i][3].y, xf, yf);

        af1 = Arie(l3, xl1, xl2);
        af2 = Arie(l2, xl1, xl3);
        af3 = Arie(l1, xl2, xl3);

        if(abs(su - af1 - af2 - af3) <= 0.1)
        {
            cnt++;
            a[cnt] = i;
        }

    }
    os << cnt << ' ';
    for(int i = 1; i <= cnt; ++i)
            os << a[i] << ' ';
    os << '\n';

    bool ok = true;
    for(int i = 1; i <= n; ++i)
    {
        if(i != imax)
        for(int j = 1; j <= 3; ++j)
        {
            if( Verificare(tr[i][j].x, tr[i][j].y) == false)
                ok = false;
        }

    }

    if(ok)
        os << imax;
    else
        os << 0;

    is.close();
    os.close();
    return 0;
}

double Latura(double x1, double y1, double x2, double y2)
{
    double l = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return l;
}

double Arie(double x1, double x2, double x3)
{
    double p = (x1 + x2 + x3) / 2;
    double a = sqrt(p * (p - x1) * (p - x2) * (p - x3));
    return a;
}

bool Verificare(int x, int y)
{
    xl1 = Latura(tr[imax][1].x, tr[imax][1].y, x, y);
    xl2 = Latura(tr[imax][2].x, tr[imax][2].y, x, y);
    xl3 = Latura(tr[imax][3].x, tr[imax][3].y, x, y);

    af1 = Arie(l3max, xl1, xl2);
    af2 = Arie(l2max, xl1, xl3);
    af3 = Arie(l1max, xl2, xl3);

    if(abs(sumax - af1 - af2 - af3) <= 0.1)
        return true;
    return false;

}

