#include <stdio.h>
#include <string.h>

#define INF 2000000000
#define MAXN 7001
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

int N, A[2][MAXN], cnt[MAXN];
int sol[2][2];

#define VMAX 500

void brute(void)
{
    int p[2][2], i, j, x, nr, val, t, mmin;

    memset(A, 0, sizeof(A));
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        scanf("%d ", &x), A[i&1][x]++;
        
    for(t = 0; t <= 1; t++)
    {
        nr = 0, mmin = INF;
        for(i = 1; i <= VMAX; i++)
        {
            for(val = 0, j = 1; j <= VMAX; j++)
                val += ABS(j-i)*A[t][j];
            if(val == mmin) nr++;
            if(val < mmin) mmin = val, nr = 1;
        }
        p[t][0] = mmin, p[t][1] = nr;
    }
    printf("%d %d\n", p[0][0]+p[1][0], p[0][1]*p[1][1]);
}

int main(void)
{
    freopen("palind.in", "rt", stdin);
    freopen("palind.out", "wt", stdout);

    int teste;

    scanf("%d ", &teste);
    while(teste--)
        brute();

    return 0;
}



