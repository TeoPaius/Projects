#include <stdio.h>

#define MAX_A 30005
#define FIN "ab.in"
#define FOUT "ab.out"
#define min(a, b) ((a) < (b) ? (a) : (b))

int N, A, B, size[MAX_A];

int main(void) 
{
    int i, j, n;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d %d %d", &N, &A, &B);

    if (N < A+B-1 || N > A*B) 
    {
        printf("Fara solutie\n");
        return 0;
    }

    n = N;
    for (i = A-1; i >= 0; --i)
    {
        size[i] = min(n-i, B);
        n -= size[i];
    }
    for (i = 0; i < A; ++i)
    {
        for (j = n+size[i]; j > n; --j)
            printf("%d ", j);
        n += size[i];
    }
    printf("\n");

    return 0;
}
