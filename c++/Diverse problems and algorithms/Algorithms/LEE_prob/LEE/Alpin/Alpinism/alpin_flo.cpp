#include <stdio.h>

#define IN "testul.2"
#define OUT "test2.out"
#define itemp icurr + di[d]
#define jtemp jcurr + dj[d]
#define MAX 201

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

int a[MAX][MAX], q, m, n, b[MAX][MAX], c[MAX][MAX][2];
int icurr, jcurr;

struct chestie {
       int val, i, j;
} sir[MAX*MAX], aux;

void Read();
void Write();
void Solve();
void Quick(int li, int ls);

int main()
{
    Read();
    Solve();
    Write();

    return 0;
}

void Read()
{
    FILE *fin = fopen(IN, "r");
    fscanf(fin, "%d", &m);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fscanf(fin, "%d", &a[i][j]);
            sir[++q].val = a[i][j];
            sir[q].i = i;
            sir[q].j = j;
        }
    fclose(fin);
}

void Solve()
{
    Quick(1, q);
    for (int i = 1; i <= q; ++i)
    {
        icurr = sir[i].i;
        jcurr = sir[i].j;
        for (int d = 0; d < 8; ++d)
            if ((itemp >= 1) && (jtemp >= 1) && (jtemp <= m) && (itemp <= m))
            if (a[icurr][jcurr] > a[itemp][jtemp])
                if (b[icurr][jcurr] < b[itemp][jtemp] + 1)
                {
                    b[icurr][jcurr] = b[itemp][jtemp] + 1;
                    c[icurr][jcurr][0] = itemp;
                    c[icurr][jcurr][1] = jtemp;
                }
    }
}

void Quick(int li, int ls)
{
    int i = li - 1, j = ls + 1, pivot = sir[li].val;
    do
    {
        do { ++i; } while (sir[i].val < pivot);
        do { --j; } while (sir[j].val > pivot);
        if (i <= j)
        {
            aux = sir[i];
            sir[i] = sir[j];
            sir[j] = aux;
        }
    } while (i <= j);
    if (i < ls) Quick(i, ls);
    if (j > li) Quick(li, j);
}

void Write()
{
    int maxus = -999999, ki = 0, kj = 0, kii = 0, kji = 0,  minus = 999999;
    FILE *fout = fopen(OUT, "w");
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (maxus < b[i][j])
            {
                maxus = b[i][j];
                ki = i;
                kj = j;
            }
            if (minus > b[i][j])
            {
                minus = b[i][j];
                kii = i;
                kji = j;
            }
        }
    fprintf(fout, "%d\n%d %d %d %d\n", b[ki][kj], kii, kji, ki, kj);
    fclose(fout);
}
