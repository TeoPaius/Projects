/*
 * pal - solutia oficiala
 * @Silviu Ganceanu
 */

#define SECURE_MODE

#include <stdio.h>

int L, A[11], nr_cifre, nr_impar;
short N[2][10010], S[10010], l[2], r[2], st[2];

void read_data()
{
	int i;
	FILE *f = fopen("pal.in", "rt");
	fscanf(f, "%d", &L);
	for (i = 0; i < 10; i ++)
		fscanf(f, "%d", A + i),
		nr_cifre += A[i],
		nr_impar += A[i] % 2;
	fclose(f);
}

void solve()
{
	#ifdef SECURE_MODE
		if (nr_cifre > 100)
			printf("ERR: Too many digits!\n");
		if (nr_impar > 2)
			printf("ERR: Nu pot fi utilizate toate cifrele!\n");
	#endif

	int x = 0, i, k, c;

	if (nr_impar == 0)
	{
		x = nr_cifre / 2;
		if (L < x) L = x;
	}

	if (nr_impar == 1)
	{
		x = nr_cifre / 2 + 1;
		if (L < x) L = x;
	}

	if (nr_impar == 2)
	{
		x = nr_cifre / 2;
		if (x % 2 == 0) x ++;      //caz important!

		if (x > L) L = x;
		else if (L % 2 == 0) L ++; //caz important!
	}

	l[0] = l[1] = 0;
	r[0] = L - 1; r[1] = nr_cifre - L - 1;
	st[0] = st[1] = 1;

	while (nr_cifre)
	{
		if (r[0] >= r[1])
			c = 0;
		else
			c = 1;

		if (l[c] > r[c])
		{
			r[c] = -1;
            continue;
		}

		if (l[c] == r[c])          //caz important!
		{
			if (nr_impar)
				for (i = st[c]; i < 10; i ++)
				if (A[i] % 2) break;
                else ;
			else
				for (i = st[c]; i < 10; i ++)
				if (A[i]) break;

			N[c][l[c]] = i, A[i] --;

			if (i == 10)
				printf("aiurea!\n");

			nr_cifre --;
			r[c] = -1;
			st[c] = 0;
		}
		else
		{
			for (i = st[c]; i < 10; i ++)
			if (A[i] > 1) break;

			if (i == 10)
				printf("aiurea!\n");

			N[c][l[c] ++] = N[c][r[c] --] = i,
			A[i] -= 2, nr_cifre -= 2;
			st[c] = 0;
		}
	}

	for (k = i = 0; i < L || i < nr_cifre - L || k; i ++, k /= 10)
		S[i] = (k += (N[0][i] + N[1][i])) % 10;
}

void paste(short X[], FILE *f)
{
	int gas, i;
	for (gas = 0, i = 10000; i >= 0; i --)
	{
		if (gas)
			fprintf(f, "%d", X[i]);
		else
			if (X[i]) fprintf(f, "%d", X[i]), gas = 1;
	}
	fprintf(f, "\n");
}

void write_data()
{
	int i, k = 0;
	FILE *f = fopen("pal.out", "wt");

	for (i = 10000; i >= 0; i --)
	if (N[0][i] != N[1][i]) break;

	if (N[0][i] < N[1][i]) k = 1;

//	paste(S, f);
	paste(N[k], f);
	paste(N[1 - k], f);

	fclose(f);
}

int main()
{
	read_data();
	solve();
	write_data();
	return 0;
}
