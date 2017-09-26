#include <stdio.h>
#include <string.h>

#define MAXN 9001
#define MAXDIV 770

int N, NR, A[MAXN], st[MAXN], pos[MAXN], sol[MAXDIV];
long steps;

int check(int K)
{
	int i, j, t = 1, p = 0, val = 0;

	for(i = 1; i <= N; i++)
	{
		steps++;
		while(t <= p && pos[t] <= i-K) val -= st[t++];
		if(A[i] < val || (i > N-K+1 && A[i] != val)) return 0;
		if(A[i] > val) pos[++p] = i, st[p] = A[i]-val, val = A[i];
	}

	return 1;
}

void read_and_solve(void)
{
	int i, j, k; long d = 0;

	scanf("%d\n", &N), NR = 0;
	for(i = 1; i <= N; i++) scanf("%d ", &A[i]), d += (long)A[i];

	for(i = 1; i <= N; i++)
	 if(check(i)) sol[++NR] = i;

	for(i = 1; i <= NR; i++) printf("%d\n", sol[i]);
}

int main(void)
{
	int teste;

	freopen("auto.in", "rt", stdin);
	freopen("auto2.out", "wt", stdout);

	scanf("%d ", &teste);
	while(teste--)
		read_and_solve();

	fprintf(stderr, "%ld\n", steps);

	return 0;
}





