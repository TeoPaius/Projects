#include <stdio.h>

#define INF 666

int N, M, Out[50], In[50];
int R[102][102], dest, flow;

int Q[102], U[102], Min[102], Up[102];

int augument(void)
{
	int i, j, head, tail;

	for (i = 0; i <= dest; i++)
		Q[i] = U[i] = Up[i] = 0, Min[i] = INF;

	U[Q[0] = 0] = 1;
	for (head = tail = 0; head <= tail; head++)
	for (i = Q[head], j = 0; j <= dest; j++)
	if (R[i][j] && !U[j])
	{
		U[Q[++tail] = j] = 1, Up[j] = i;
		Min[j] = Min[i] < R[i][j] ? Min[i] : R[i][j];
		if (j == dest) return 1;
	}
	return 0;
}

int main(void)
{
	FILE *f;
	int i, j;

	f = fopen("pluto.in", "r");
	fscanf(f, "%d %d\n", &N, &M);
	for (i = 0; i < N; i++)
		fscanf(f, "%d", Out + i); // fscanf(f, "%d", Out + i));
	for (i = 0; i < N; i++)
		fscanf(f, "%d", In + i);
	fclose(f);

	dest = 2 * N + 1;
	for (i = 0; i < N; i++)
		R[0][i + 1] = Out[i],
		R[N + i + 1][dest] = In[i];

	for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		R[i][N + j] = (i != j);

	for (; augument(); flow += Min[dest])
	for (i = dest; i > 0; i = Up[i])
		R[Up[i]][i] -= Min[dest],
		R[i][Up[i]] += Min[dest];

	if (flow != M)
	{
		f = fopen("pluto.out", "w");
		fprintf(f, "NO\n");
		fclose(f);
		return 0;
	}

	f = fopen("pluto.out", "w");
	fprintf(f, "YES\n");
	for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		if (R[j + N][i]) fprintf(f, "%d %d\n", i, j);
	fclose(f);

	return 0;
}
