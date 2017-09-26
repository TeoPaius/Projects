#include <stdio.h>

#define MAXN 100005

int A[MAXN], B[MAXN], Nr[MAXN];
int y1,y2,i,j,rasp;
int N,K,Q;

int main()
{
	freopen("ozn.in","r",stdin);
	freopen("ozn.out","w",stdout);
	
	scanf("%d %d",&N,&K);
	for (i = 1; i <= N; ++i)
		scanf("%d %d %d %d %d", &A[i], &y1, &B[i], &y2, &Nr[i]);
	
	for (i = 1; i <= K; ++i){
		scanf("%d",&Q);
		rasp = 0;
		for (j = 1; j <= N; ++j)
			if (A[j] <= Q && Q <= B[j])
				rasp += Nr[j];
		printf("%d\n", rasp);
	}
	
	return 0;
}