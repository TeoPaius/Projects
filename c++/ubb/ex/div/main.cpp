#include <fstream>
#include <vector>
using namespace std;
ifstream is("div.in");
ofstream os("div.out");


void Citire(int &n, int x[]);
void Afisare(int x[], int n);
bool Prim(int x);
void AddToY(int x, bool found[], int y[], int& cnt);

int main()
{

    int n;
    int x[1000] = {0};
    int y[1000] = {0};
    int aux;
    bool used[1000] = {false};
    bool found[1000] = {false};
    int cnt = 0;

    Citire(n, x);

    for(int i = 1; i <= n; ++i)
    {
        if(!used[x[i]])
        {
            used[x[i]] = true;
            aux = x[i];
            for(int j = 2; j <= aux; ++j)
            {
                if(Prim(j))
                {
                    if(aux % j == 0)
                    {
                        aux /= j;
                        if(aux % j == 0)
                            continue;
                        else
                            AddToY(j, found, y, cnt);
                    }
                }
            }
        }
    }

    Afisare(y, cnt);

    is.close();
    os.close();
    return 0;
}

void Citire(int &n, int x[])
{
    is >> n;
    for(int i = 1; i <= n; ++i)
    {
        is >> x[i];

    }
}

void Afisare(int x[], int n)
{
    if(n == 0)
    {
        os << "sir vid";
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        os << x[i] << ' ';
    }
}

bool Prim(int x)
{
    if(x == 2)
        return true;
    if(x % 2 == 0)
        return false;
    for(int d = 3; d*d <= x; d+=2)
        if(x % d == 0)
            return false;
    return true;
}

void AddToY(int x, bool found[], int y[], int& cnt)
{
    if(found[x])
        return;
    else
    {
        found[x] = true;

        y[cnt] = x;
        cnt++;
    }
}
