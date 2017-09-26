/* Sursa 100% */

#include <stdio.h>
#include <math.h>

#define MN 20
#define EPS 1e-6
#define SQR(a) ( (double) (a) * (double) (a) )

int N, X1[MN], Y1[MN], X2[MN], Y2[MN], viz[MN], st[MN];
double sol;

void read_data()
{
	int i;
	FILE *f = fopen("seceta.in", "rt");
	fscanf(f, "%d", &N);
	for (i = 0; i < N; i ++)
		fscanf(f, "%d %d", X1 + i, Y1 + i);
	for (i = 0; i < N; i ++)
		fscanf(f, "%d %d", X2 + i, Y2 + i);
	fclose(f);
}

int la_dr(int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
	int t = (Cx - Ax) * (By - Ay) - (Cy - Ay) * (Bx - Ax);
    return t < 0 ? -1 : t > 0 ? 1 : 0;
}

int inter(int Ax, int Ay, int Bx, int By,
		  int Cx, int Cy, int Dx, int Dy)
{
	int gas = 0;
	if (la_dr(Ax, Ay, Bx, By, Cx, Cy) * la_dr(Ax, Ay, Bx, By, Dx, Dy) < 0)
		gas ++;
	if (la_dr(Cx, Cy, Dx, Dy, Ax, Ay) * la_dr(Cx, Cy, Dx, Dy, Bx, By) < 0)
		gas ++;
	return gas > 1;
}

double dst_fun(int x, int y)
{
	return sqrt( SQR(X1[x] - X2[y]) + SQR(Y1[x] - Y2[y]) );
}

void perm(int lev, double sum)
{
	if (sum - sol > EPS)
		return ;
	if (lev == N)
	{
		sol = sum;
        return ;
	}
	int i, k;
	for (i = 0; i < N; i ++)
	if (viz[i] == 0)
	{
		for (k = 0; k < lev; k ++)
		if (inter(X1[k], Y1[k], X2[st[k]], Y2[st[k]],
				  X1[lev], Y1[lev], X2[i], Y2[i]))
				  break;

		if (k == lev)
		{
			st[lev] = i;
			viz[i] = 1;
			perm(lev + 1, sum + dst_fun(lev, i)); //verificat optimizare
			viz[i] = 0;
		}
	}
}

void solve()
{
	/* optimizare distante */
	sol = 1e9;
	perm(0, 0);
}

void write_data()
{
	FILE *f = fopen("seceta.out", "wt");
	fprintf(f, "%ld\n", (long) floor(sol * 100));
	fclose(f);
}

int main()
{
	read_data();
	solve();
	write_data();
	return 0;
}
