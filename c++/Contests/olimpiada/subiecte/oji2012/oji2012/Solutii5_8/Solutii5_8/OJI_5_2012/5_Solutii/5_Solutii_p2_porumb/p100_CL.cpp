//prof. Chira Liliana
#include<cstdio>
using namespace std;
int n,x;
int main()
{
	int m=1,k=0,nr=0;
	freopen("porumb.in","r",stdin);
	freopen("porumb.out","w",stdout);
	scanf("%d%d", &n, &x);
	printf("%d\n", (n+1)/2);
	while(m<=n)
		m*=2;
	m/=2;
	while(x%2==0)
	{
		x/=2;
		k++;
	}
	while(n!=0)
	{
		nr++;
		n/=2;
	}
	printf("%d\n%d\n%d\n", nr , k+1, m);
	return 0;
}
