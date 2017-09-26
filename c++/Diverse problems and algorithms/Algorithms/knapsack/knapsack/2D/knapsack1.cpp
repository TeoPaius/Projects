#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("knapsack.in");
ofstream fout("knapsack.out");

const int MaxN = 100;
const int MaxG = 1000;
int n, G; // nr ob, cap rucsacului
int g[MaxN], v[MaxN];  // greutati, valori
int c[MaxN][MaxG];  // c[i][j] - val maxima a unor obiecte
                    // alese din intervalul [1..i], a.i.
                    // greutatea lor sa nu depaseasca j

void Read();
void Knapsack();

int main()
{
    Read();
    Knapsack();

    fout << c[n][G];

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
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= G; ++j)
        {
            // daca nu introduc obiectul i in rucsac
            c[i][j] = c[i - 1][j];

            // daca nu introduc obiectul i in rucsac
            if ( j >= g[i] &&
                 c[i][j] < c[i - 1][j - g[i]] + v[i])
             c[i][j] = c[i - 1][j - g[i]] + v[i];
        }
}
