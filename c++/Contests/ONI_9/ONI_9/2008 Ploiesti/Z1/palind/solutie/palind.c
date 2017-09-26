#include <stdio.h>
#include <string.h>

#define INF 2000000000
#define MAXN 7001
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

int N, A[2][MAXN], cnt[MAXN];
int sol[2][2];

void baga(int t)
{
    int i, nr, val, x, mmin = INF;
    memset(cnt, 0, sizeof(cnt));
    for(val = nr = 0, i = 1; i < MAXN; i++)
        val += nr, val += A[t][i-1], nr += A[t][i-1], cnt[i] += val;
    for(nr = val = 0, i = MAXN-2; i >= 1; i--)
        val += nr, val += A[t][i+1], nr += A[t][i+1], cnt[i] += val;
    for(nr = 0, i = 1; i < MAXN; i++)
    {
        if(cnt[i] == mmin) nr++;
        if(cnt[i] < mmin) mmin = cnt[i], nr = 1;
    }
    sol[t][0] = mmin, sol[t][1] = nr;
}

void solve(void)
{
    int i, val, x;

    memset(A, 0, sizeof(A));
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        scanf("%d", &x), A[i&1][x]++;

    baga(0), baga(1);
    printf("%d %d\n", sol[0][0]+sol[1][0], sol[0][1]*sol[1][1]);
}

#define VMAX 7000

void brute(void)
{
    int p[2][2], i, j, x, nr, val, t, mmin;

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
    fprintf(stderr, "%d %d\n", p[0][0]+p[1][0], p[0][1]*p[1][1]);
}

int main(void)
{
    freopen("palind.in", "rt", stdin);
    freopen("palind.out", "wt", stdout);

    int teste;

    scanf("%d ", &teste);
    while(teste--)
        solve();//, brute();

    return 0;
}



