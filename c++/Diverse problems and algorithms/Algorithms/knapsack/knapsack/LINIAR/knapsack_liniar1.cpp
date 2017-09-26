#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("knapsack.in");
ofstream fout("knapsack.out");

const int MaxN = 100;
const int MaxG = 1000;
const int Necalculat = -1;
int n, G; // nr ob, cap rucsacului
int g[MaxN], v[MaxN];  // greutati, valori
int c[MaxG];  // c[j] - val maxima a unor obiecte
                    // alese din intervalul [1..i], a.i.
                    // greutatea lor sa fie EXACT j
int Vmax, Gmax;
void Read();
void Knapsack();
void Write(int i, int s);

int main()
{
    Read();
    Knapsack();
    fout << Vmax << ' ' << Gmax;
    fout << '\n';

    fin.close();
    fout.close();
}

void Read()
{
    fin >> n >> G;
    for (int i = 1; i <= n; ++i)
        fin >> g[i];
    for (int i = 1; i <= n; ++i)
        fin >> v[i];
}

void Knapsack()
{
    for ( int j = 0; j <= G; ++j)
        c[j] = Necalculat;
    c[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = G - g[i]; j >= 0; --j)
            if ( c[j] != Necalculat &&
                c[j + g[i]] < c[j] + v[i])
                c[j + g[i]] = c[j] + v[i];

    for (int j = 0; j <= G; ++j)
        if (c[j] > Vmax )
        {
            Vmax = c[j];
            Gmax = j;
        }
}
