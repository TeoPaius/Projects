#include<stdio.h>

int d[3500],g[3500],c[12881];
int n,m;

int main()
{	freopen("charm.in","r",stdin);
	freopen("charm.out","w",stdout);
	int i,j,max=0;

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d%d",&g[i],&d[i]);
	c[0]=0;
	for(i=1;i<=m;i++)
		c[i]=-1;
	for(i=1;i<=n;i++)
		for(j=m-g[i];j>=0;j--)
			if(c[j]!=-1)
			if(c[j+g[i]]<c[j]+d[i])
				c[j+g[i]]=c[j]+d[i];
	for(i=m;i>=0;i--)
		if(max<c[i]) max=c[i];
	printf("%d\n",max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}