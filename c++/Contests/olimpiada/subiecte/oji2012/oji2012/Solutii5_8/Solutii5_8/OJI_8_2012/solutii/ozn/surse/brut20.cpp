#include <stdio.h>

int Ap[2000010];
int N,K,i,x1,x2,y1,y2,val;

int main()
{
	freopen("ozn.in","r",stdin);
	freopen("ozn.out","w",stdout);
	
	scanf("%d %d",&N,&K);
	for (i=1; i<=N; ++i){
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&val);
		for (; x1<=x2; ++x1)
			Ap[x1] += val;
	}
	
	for (i=1; i<=K; ++i){
		scanf("%d",&x1);
		printf("%d\n", Ap[x1]);
	}
	
	return 0;
}