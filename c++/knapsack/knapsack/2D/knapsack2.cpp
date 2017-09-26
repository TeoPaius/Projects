#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("knapsack.in");
ofstream fout("knapsack.out");

const int MaxN = 100;
const int MaxG = 1000;
int n, G; // nr ob, cap rucsacului
int t[MaxN][MaxG];
int g[MaxN], v[MaxN];  // greutati, valori
int c[MaxN][MaxG];  // c[i][j] - val maxima a unor obiecte
                    // alese din intervalul [1..i], a.i.
                    // greutatea lor sa nu depaseasca j

void Read();
void Knapsack();
void Write(int i, int s);


int main()
{
    Read();
    Knapsack();

    fout << c[n][G] << '\n';
    Write(n, G);

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
            t[i][j] = t[i - 1][j];
            // daca introduc obiectul i in rucsac
            if ( j >= g[i] &&
                 c[i][j] < c[i - 1][j - g[i]] + v[i])
            {
                c[i][j] = c[i - 1][j - g[i]] + v[i];
                t[i][j] = g[i];
            }
        }
}

void Write(int i, int s)
{
    if ( !i || !s ) // nu mai am obiecte in rucsac
       return;      // sau greutatea lui e 0
    if ( t[i][s] == t[i - 1][s])
        Write(i - 1, s);
    else
    {
        Write(i - 1, s - t[i][s]);
        fout << t[i][s] << ' ';
       // fout << g[i] << ' ';
    }

}

