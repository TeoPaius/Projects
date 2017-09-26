#include <stdio.h>

#define MAXX 2000010
#define MAXN 100010

int A[MAXX];
int N,K;
int x1,y1,x2,y2,nr,i;

int main()
{
	freopen("ozn.in","r",stdin);
	freopen("ozn.out","w",stdout);
	
	scanf("%d %d",&N,&K);
	for (i=1; i <= N; ++i){
		scanf("%d %d %d %d %d",&x1,&y2,&x2,&y2,&nr);
		A[x1]+=nr;
		A[x2+1]-=nr;
	}
	
	for (i = 1; i < MAXX; ++i)
		A[i] += A[i-1];
	
	for (i = 1; i <= K; ++i){
		scanf("%d", &x1);
		printf("%d\n", A[x1]);
	}
	
	return 0;
}