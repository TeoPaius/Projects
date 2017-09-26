#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DimMax  128

char G[DimMax][DimMax];
char T[DimMax][DimMax];
int N, L4, NrG;
FILE *FOUT;
char MOK[5024], ME[5024];

void Error(int Puncte, char * Mesaj)
{
  printf("%d %s\n", Puncte, Mesaj);
  exit(0);
}

void delete_eol(char *s)
{
	char *c;

	for (c = s; (*c != 10) && (*c != 13) && (*c != '\r') && (*c != '\n') && (*c != 0); c++);
	*c = 0;
}

void Citire(void)
{
	FILE * f;
	int    i, j;
	int    Lung;
	int	len;
	char temp[1024];

	f=fopen("sablon.in","r");
	Lung = 0;
	fgets(MOK, 1024, f);
	delete_eol(MOK);
	len = strlen(MOK);
    for (i = len; i > 0; i--)
        MOK[i] = MOK[i - 1];
//	memmove(&MOK[1], &MOK[0], len + 1);
	Lung=strlen(MOK);
	fgets(temp, 1024, f);
	sscanf(temp,"%d",&N);
	for (i = 1; i <= N; i++)
	{
	    fgets(T[i], 1024, f);
	    delete_eol(T[i]);
	    len = strlen(T[i]);
        for (j = len; j > 0; j--)
            T[i][j] = T[i][j - 1];
//	    memmove(&T[i][1], &T[i][0], len + 1);
	}
	fclose(f);
	L4 = Lung / 4;
}

void Citire_Sablon(void)
{int i, j;
int len;
 FOUT=fopen("sablon.out","r");
 for (i=1; i<=N; i++)
 {
     fgets(G[i], 1024, FOUT);
     delete_eol(G[i]);
     len = strlen(G[i]);
     if (len != N)
     	Error(0, "Dimensiune sablon incorecta");
     for (j = len; j > 0; j--)
         G[i][j] = G[i][j - 1];
//     memmove(&G[i][1], &G[i][0], len + 1);
 }
fclose(FOUT);
}

void Refa_Mesaj(void)
{
	int i, j;
	int AB[DimMax][DimMax], nrsol;

memset(AB, 0, sizeof(AB));
for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		if (G[i][j] == 'O')
		{
			AB[i][j] = 1;
			AB[j][N - i + 1] = 1;
			AB[N - i + 1][N - j + 1] = 1;
			AB[N - j + 1][i] = 1;
		}
nrsol = 0;
for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		nrsol += AB[i][j];
if (nrsol != 4 * L4)
	Error(0, "Gaurile se suprapun prin rotatie");

  NrG = 0;
  for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		if (G[i][j] == 'O')
		{
			NrG++;
			ME[NrG] = T[i][j];
			ME[L4 + NrG] = T[j][N - i + 1];
			ME[2 * L4 + NrG] = T[N - i + 1][N - j + 1];
			ME[3 * L4 + NrG] = T[N - j + 1][i];
		}
}

int main(void)
{
    int i;

	Citire();
	Citire_Sablon();
	Refa_Mesaj();
	for (i = 1; i <= 4 * L4; i++)
	      if (MOK[i] != ME[i])
			Error(0, "Incorect");
	Error(10, "OK");

	return 0;
}
