
#include <stdio.h>
#include <string.h>

#define MAXN 110

char sol[MAXN][MAXN];
int N, lin, col, lun, rot, n_lun, colt, litera;

int okay(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 1;
	return sol[x][y] != '.';
}

int paste()
{
	int i, j, k;
	if (rot == 0)
	{
		for (i = 0, k = 1; i < lun; i ++, k ++)
		for (j = 0; j < k; j ++)
			if (okay(lin - j, col + i)) return 0;

		for (i = 0, k = 1; i < lun; i ++, k ++)
		for (j = 0; j < k; j ++)
			sol[lin - j][col + i] = litera + 'a';
	}
	if (rot == 1)
	{
		for (i = 0, k = 0; i <= lun; i ++, k ++)
		for (j = k; j < lun; j ++)
			if (okay(lin - j, col - i)) return 0;

		for (i = 0, k = 0; i <= lun; i ++, k ++)
		for (j = k; j < lun; j ++)
			sol[lin - j][col - i] = litera + 'a';
	}
	if (rot == 2)
	{
		for (i = 0, k = 1; i < lun; i ++, k ++)
		for (j = 0; j < k; j ++)
			if (okay(lin + j, col - i)) return 0;

		for (i = 0, k = 1; i < lun; i ++, k ++)
		for (j = 0; j < k; j ++)
			sol[lin + j][col - i] = litera + 'a';
	}
	if (rot == 3)
	{
		for (i = 0, k = 0; i < lun; i ++, k ++)
		for (j = k; j < lun; j ++)
			if (okay(lin + j, col + i)) return 0;

		for (i = 0, k = 0; i < lun; i ++, k ++)
		for (j = k; j < lun; j ++)
			sol[lin + j][col + i] = litera + 'a';
	}

	litera = (litera + 1) % 26;
	return 1;
}

void read_data()
{
	FILE *f = fopen("joc.in", "rt");
	fscanf(f, "%d", &N);
	memset(sol, '.', sizeof(sol));
	fscanf(f, "%d %d %d", &lin, &col, &lun);
	litera = 0;
	lin --, col --, rot = 0;

	while(1)
	{
		if (paste() == 0)
		{
			rot = (rot + 1) % 4;
			if (paste() == 0)
				return ;
		}

		if (fscanf(f, "%d %d", &colt, &n_lun) == EOF)
			break;

		if (litera == 6)
		   litera = 6;

		if (rot == 0)
			if (colt == 2) col += lun;
			else	       lin -= lun, col += lun - 1;
		if (rot == 1)
			if (colt == 2) lin -= lun;
			else	       lin -= lun - 1, col -= lun;
		if (rot == 2)
			if (colt == 2) col -= lun;
			else		   col -= lun - 1, lin += lun;
		if (rot == 3)
			if (colt == 2) lin += lun;
			else		   lin += lun - 1, col += lun;

		lun = n_lun;
	}

	fclose(f);
}

void write_data()
{
	int i, j;
	FILE *f = fopen("joc.out", "wt");
	for (i = 0; i < N; i ++)
	{
		for (j = 0; j < N; j ++)
			fprintf(f, "%c", sol[i][j]);
		fprintf(f, "\n");
	}
	fclose(f);
}

int main()
{
	read_data();
	write_data();
	return 0;
}
