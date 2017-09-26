#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("tir.in");
ofstream fout("tir.out");

const int MaxN = 100;
const int MaxG = 1000;
const int Necalculat = 0x3f3f3f3f;

int n, G; // nr ob, punctajul care trebuie obtinut
int g[MaxN];  // g[i] - punctajul cercului i
int c[MaxG];  // c[j] - numarul minim de trageri
              // cu care se obtine EXACT punctajul j
int t[MaxG];

void Read();
void Knapsack();
void Write(int s);

int main()
{
    Read();
    Knapsack();
    if ( c[G] == Necalculat )
        fout << 0 << '\n';
    else
    {
        fout << c[G] << '\n';
        Write(G);
    }

    fin.close();
    fout.close();
}

void Read()
{
    fin >> n >> G;
    for (int i = 1; i <= n; ++i)
        fin >> g[i];
}

void Knapsack()
{
    for ( int j = 0; j <= G; ++j)
        c[j] = Necalculat;
    c[0] = 0; // punctajul 0 se obtine cu 0 trageri

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= G - g[i]; ++j)
            if ( c[j] != Necalculat &&
                c[j + g[i]] > c[j] + 1)
            {
                c[j + g[i]] = c[j] + 1;
                t[j + g[i]] = g[i];
            }
}

void Write(int s) // punctajul curent
{
    if ( s == 0 )
        return;
    Write(s - t[s]);
    fout << t[s] << ' ';
}

