
#include <stdio.h>
#include <string.h>

#define MAXN    100
#define MOD     13007
#define pos(i, j)    ((i) * n + (j))
#define sw(x, y)    (aux = A[x], A[x] = A[y], A[y] = aux)

int A[MAXN * MAXN], n, m;
char B[MAXN * MAXN];
int P[MAXN * MAXN], np = 0;
short E[MAXN * MAXN];

void dump() {
    int i, j;
    printf("%d %d\n", n, m);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf(" %d", A[pos(i, j)]);
        printf("\n");
    }
}

void read_eval() {
    int i, j, z, a, b, c, d, aux;
    char op[10];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n * n; ++i)
        A[i] = i;
    for (z = 0; z < m; ++z) {
        scanf("%s%d%d", op, &a, &b);
        // printf("I: %s %d %d\n", op, a, b);
        --a, --b;
        switch (op[0]) {
            case 'R':
                for (j = 0; j < n; ++j)
                    sw(pos(a, j), pos(b, j));
                break;
            case 'C':
                for (i = 0; i < n; ++i)
                    sw(pos(i, a), pos(i, b));
                break;
            case 'E':
                scanf("%d%d", &c, &d);
                --c, --d;
                sw(pos(a, b), pos(c, d));
                break;
            default:
                //printf("ERROR: %s\n", op);
                break;
        }
    }
}

void cycles() {
    int i, len, j, d, pow, x;
    memset(B, 0, MAXN * MAXN);
    memset(E, 0, MAXN * MAXN);
    for (i = 0; i < n * n; ++i) {
        for (len = 0, j = i; !B[j]; ++len) {
            // printf("c: \t%d\n", j);
            B[j] = 1;
            j = A[j];
        }
        if (len) {
            // printf("<<< %d\n", len);
            for (x = len, d = 0; x > 1 && P[d] * P[d] <= x && d < np; ++d) {
                // printf("e: %d, %d, %d\n", d, P[d], x);
                for (pow = 0; x % P[d] == 0; ++pow)
                    x /= P[d];
                if (E[P[d]] < pow) {
                    E[P[d]] = pow;
                }
            }
            if (x > 1 && !E[x]) {
                E[x] = 1;
            }
            // dump_exp();
        }
    }
}

void gen_primes() {
    int a, j, i;
    P[np++] = 2;
    for (a = 3; a < n * n; a += 2) {
        char prim = 1;
        for (j = 0; prim && (P[j] * P[j] <= a) && j < np; ++j) {
            prim = ((a % P[j]) != 0);
        }
        if (prim) {
            P[np++] = a;
        }
    }
}

void dump_exp() {
    int i;
    printf("exp:\n");
    for (i = 0; i < n * n; ++i) {
        if (E[P[i]])
            printf(" %d^%d", P[i], E[P[i]]);
    }
    printf("\n");
}

void dump_primes() {
    int i;
    printf("primes:\n");
    for (i = 0; i < np; ++i) {
        printf(" %d", P[i]);
    }
    printf("\n");
}

int cmmmc() {
    int i, res, j;
    for (res = 1, i = 1; i < n * n; ++i) {
        for (j = 0; j < E[i]; ++j)
            res = (((long long)res * (i % MOD)) % MOD);
    }
    return res;
}

int main(void) {
    freopen("perspic.in", "rt", stdin);
    freopen("perspic.out", "wt", stdout);
    read_eval();
    // dump();
    gen_primes();
    // dump_primes();
    cycles();
    printf("%d\n", cmmmc());
    return 0;
}

