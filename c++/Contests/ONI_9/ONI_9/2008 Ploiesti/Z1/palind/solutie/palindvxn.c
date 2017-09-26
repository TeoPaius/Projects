#include <stdio.h>
#include <string.h>

#define INF 2000000000
#define MAXN 7001
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

int N, A[2][MAXN], cnt[2];
int sol[2][2];

void solve(void)
{
    int i, val, t, x, j, nr, mmin = INF;

    memset(A, 0, sizeof(A)), cnt[0] = cnt[1] = 0;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
        scanf("%d", &x), A[i&1][ ++cnt[i&1] ] = x;

    for(t = 0; t <= 1; t++)
    {
        nr = 0, mmin = INF;
        for(i = 1; i < MAXN; i++)
        {
            for(val = 0, j = 1; j <= cnt[t]; j++)
                val += ABS(i-A[t][j]);
            if(val == mmin) nr++;
            if(val < mmin) mmin = val, nr = 1;
        }
        sol[t][0] = mmin, sol[t][1] = nr;
    }

    printf("%d %d\n", sol[0][0]+sol[1][0], sol[0][1]*sol[1][1]);
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



