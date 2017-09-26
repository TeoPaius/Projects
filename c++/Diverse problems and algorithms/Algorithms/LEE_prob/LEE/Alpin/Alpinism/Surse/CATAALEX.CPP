/* Alexandru Catalin */
/* bcc -mc -O2 */

#include <stdio.h>
#include <alloc.h>
#define Up 1
#define Left 2
#define Right 4
#define Down 8

int N;
int far H1[202][101], far H2[202][101];
unsigned far L1[202][101], far L2[202][101];
char far D[202][202];
char far F[202][202];

// eu am comentat: H - matricea inaltimilor
// D - matricea directiilor
inline int& H(int X, int Y) { if (Y >= 101) return H2[X][Y-101]; else return H1[X][Y]; }
inline unsigned& L(int X, int Y) { if (Y >= 101) return L2[X][Y-101]; else return L1[X][Y]; }

void ReadData()
{
	FILE* f = fopen("alpin.in", "rt");
	fscanf(f, "%d", &N);
	for (int i = 1, j; i <= N; i++)
		for (j = 1; j <= N; j++)
			fscanf(f, "%d", &H(i,j));
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			if (i > 1) if (H(i-1,j) < H(i,j)) D[i][j] = D[i][j] | Up;
			if (i < N) if (H(i+1,j) < H(i,j)) D[i][j] = D[i][j] | Down;
			if (j > 1) if (H(i,j-1) < H(i,j)) D[i][j] = D[i][j] | Left;
			if (j < N) if (H(i,j+1) < H(i,j)) D[i][j] = D[i][j] | Right;
			F[i][j] = D[i][j];
		}
	fclose(f);
}

void MakeMatrix()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (!D[i][j])
			{
				int x = i, y = j;
				if (D[i+1][j] & Up) D[i+1][j] = D[i+1][j] ^ Up;
				if (D[i][j+1] & Left) D[i][j+1] = D[i][j+1] ^ Left;
				if (D[i][j-1] & Right) { D[i][j-1] = D[i][j-1] ^ Right; if (!D[i][j-1]) { x = i; y = j-2; } }
				if (D[i-1][j] & Down) { D[i-1][j] = D[i-1][j] ^ Down; if (!D[i-1][j]) { x = i-1; y = j-1; } }
				D[i][j] = -1;
				if (F[i][j] & Down) { if (L(i+1,j) >= L(i,j)) L(i,j) = L(i+1,j) + 1; }
				if (F[i][j] & Right) { if (L(i,j+1) >= L(i,j)) L(i,j) = L(i,j+1) + 1; }
				if (F[i][j] & Left) { if (L(i,j-1) >= L(i,j)) L(i,j) = L(i,j-1) + 1; }
				if (F[i][j] & Up) { if (L(i-1,j) >= L(i,j)) L(i,j) = L(i-1,j) + 1; }
				i = x; j = y;
			}
		}
}

void WriteData()
{
	FILE* f = fopen("alpin.out", "wt");
	int X, Y;
	long M = -1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			if (L(i,j) > M)
			{
				X = i;
				Y = j;
				M = L(i,j);
			}
	}
	fprintf(f, "%ld\n", M);
	int XX = X, YY = Y;
	while (L(X,Y))
	{
		if (F[X][Y] & Up) { if (L(X,Y) == L(X-1,Y)+1) { X--; continue; } }
		if (F[X][Y] & Down) { if (L(X,Y) == L(X+1,Y)+1) { X++; continue; } }
		if (F[X][Y] & Right) { if (L(X,Y) == L(X,Y+1)+1) { Y++; continue; } }
		if (F[X][Y] & Left) { if (L(X,Y) == L(X,Y-1)+1) { Y--; continue; } }
	}
	fprintf(f, "%d %d %d %d", X, Y, XX, YY);
	fclose(f);
}

void main()
{
	ReadData();
	MakeMatrix();
	WriteData();
}