/*
 * BIFO : Solutia oficiala
 * @Silviu Ganceanu
 */

#include <stdio.h>
#include <string.h>

#define MN 402
#define ML 52

#ifndef __BORLANDC__
	#define huge
#endif

typedef char lnum[ML];

int M;
char A[2][MN], sol[MN];
lnum  P[MN],  F[MN], S[MN], T, max;

int cmp(lnum A, lnum B)
{
	if (A[0] - B[0])
		return A[0] - B[0];
	int i;
	for (i = A[0]; i > 0; i --)
	if (A[i] - B[i])
		return A[i] - B[i];
    return 0;
}

void init(lnum T, int x)
{
	memset((void *)T, 0, sizeof(lnum));
	for (; x; x /= 10)
    	T[++ T[0]] = x % 10;
}

void add(lnum A, lnum B)
{
	int i, t = 0;
	for (i = 1; i <= A[0] || i <= B[0] || t; i ++, t /= 10)
		A[i] = (t += (A[i] + B[i])) % 10;
	A[0] = i - 1;
}

void diff(lnum A, lnum B)
{
	int i, j;

	for (i = 1; i <= B[0]; i ++)
	if (A[i] >= B[i])
		A[i] -= B[i];
	else
	{
		for (j = i + 1; A[j] == 0; j ++)
			A[j] = 9;
		A[j] --;
		A[i] = A[i] + 10 - B[i];
	}
	for (; A[0] > 0 && A[ A[0] ] == 0; A[0] --)
		;
}

void read_data()
{
	int i, j;
	char line[ML];
	FILE *f = fopen("bifo.in", "rt");

	fscanf(f, "%s\n", A[0]);
	fscanf(f, "%s\n", A[1]);

	fscanf(f, "%d\n", &M);

	for (i = 0; i < M; i ++)
	{
		fscanf(f, "%s\n", line);
		memset((void *)P[i], 0, sizeof(P[i]));
		for (j = strlen(line) - 1; j >= 0; j --)
			P[i][++P[i][0]] = line[j] - '0';

		if (cmp(P[i], max) > 0)
        	memcpy(max, P[i], sizeof(lnum));
	}

	fclose(f);
}

void solve()
{
	int k, i, j;
	long t;

	init(F[1], strlen(A[0]));
    init(F[2], strlen(A[1]));
	add(S[1], F[1]);
	add(S[2], F[1]), add(S[2], F[2]);

	for (i = 3; cmp(S[i - 1], max) <= 0; i ++)
	{
		memcpy(F[i], F[i - 1], sizeof(lnum));
		add(F[i], F[i - 2]);
		memcpy(S[i], S[i - 1], sizeof(lnum));
		add(S[i], F[i]);
	}

	for (k = 0; k < M; k ++)
	{
		for (i = 0; cmp(S[i], P[k]) < 0; i ++)
			;
		i --;
		memcpy(T, P[k], sizeof(lnum));
		diff(T, S[i]);

		for (++ i; i > 2;)
		{
			if (cmp(T, F[i - 2]) > 0)
				diff(T, F[i - 2]), i --;
			else
				i -= 2;
		}

		for (j = T[0], t = 0; j > 0; j --)
			t = t * 10 + T[j];
		sol[k] = A[i - 1][t - 1];
	}
	sol[M] = '\0';
}

void write_data()
{
	FILE *f = fopen("bifo.out", "wt");
	fprintf(f, "%s\n", sol);
	fclose(f);
}

int main()
{
	read_data();
	solve();
	write_data();
	return 0;
}
