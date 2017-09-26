#include <stdio.h>
#include <string.h>

#define MAX_N 55005
#define FIN "teatru.in"
#define FOUT "teatru.out"

int N, C, bst_len, start;
char S[MAX_N], cnt[26];

int main(void)
{
	int i, j, k;
	
	freopen(FIN, "r", stdin);
	freopen(FOUT, "w", stdout);

	scanf("%d %d %s", &N, &C, S);

	for (i = 0; i < N; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		for (j = i, k = 0; j < N && k <= C; ++j)
		{
			if (!cnt[S[j]-'A']) { ++k; cnt[S[j]-'A'] = 1; }
			if (k == C && bst_len < j-i+1) 
			{
				bst_len = j-i+1;
				start = i;
			}
		}
	}

	printf("%d\n", bst_len);
	for (i = start; i < start+bst_len; ++i)
		printf("%c", S[i]);
	printf("\n");

	return 0;
}
