#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("knapsack.in");
ofstream fout("knapsack.out");

const int MaxN = 100;
const int MaxG = 1000;
int n, G; // nr ob, cap rucsacului
int g[MaxN], v[MaxN];  // greutati, valori
int c[2][MaxG];  // c[i][j] - val maxima a unor obiecte
                    // alese din intervalul [1..i], a.i.
                    // greutatea lor sa nu depaseasca j
int lc, lp;
void Read();
void Knapsack();
void Write(int i, int s);

int main()
{
    Read();
    Knapsack();

    fout << c[lp][G] << '\n';

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
    lc = 1;
    for (int i = 1; i <= n; ++i, lc = !lc, lp = !lp)
        for (int j = 0; j <= G; ++j)
        {
            // daca nu introduc obiectul i in rucsac
            c[lc][j] = c[lp][j];
            // daca introduc obiectul i in rucsac
            if ( j >= g[i] &&
                 c[lc][j] < c[lp][j - g[i]] + v[i])
            {
                c[lc][j] = c[lp][j - g[i]] + v[i];
            }
        }
}
