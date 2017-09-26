//Marcu Ovidiu
#include<iostream>
#include<iomanip>
using namespace std;

long long a[1001][1001],p,v,x[1001],m,n,i,j;
void citire()
{cin>>n;
for(i=n;i>=1;i--)
 {cin>>p>>v;
 x[i]=p;
// y[i]=v;
 a[i][p]=v;
 }
}
void sol()
{for(i=1;i<=n;i++)
  { p=x[i];//a[i][p]are valoare 
	   for(j=p+1;j<=i;j++) // completez la dreapta
		    a[i][j]=a[i-1][j-1]-a[i][j-1];
	   for(j=p-1;j>=1;j--)
		   a[i][j]=a[i-1][j]-a[i][j+1];
  } 
}
void afis()
{
  unsigned int i;
  for(i=1;i<=n;i++)
	cout<<a[n][i]<<" ";  
}
int main()
{freopen("triunghi.in","r",stdin);
 freopen("triunghi.out","w",stdout);
citire();
sol();
afis();
 
return 0;
}
