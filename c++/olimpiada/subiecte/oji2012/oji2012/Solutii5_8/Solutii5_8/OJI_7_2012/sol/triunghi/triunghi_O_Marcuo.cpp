//Marcu Ovidiu
#include<iostream>
#include<iomanip>
using namespace std;
long long p,v,x[1001],y[1001],s1[1001],s2[1001],m,n,i,j;
void citire()
{cin>>n;
for(i=n;i>=1;i--)
 {cin>>p>>v;
 x[i]=p;
 y[i]=v;
 }
}
void sol()
{  s1[x[1]]=y[1];
  for(i=2;i<=n;i++)
  { p=x[i];
    v=y[i];
	s2[p]=v;
	for(j=p+1;j<=i;j++)
		s2[j]=s1[j-1]-s2[j-1];
	for(j=p-1;j>=1;j--)
		s2[j]=s1[j]-s2[j+1];
	for(j=1;j<=i;j++)
		s1[j]=s2[j];
  }	  

}
void afis()
{
  int i;
  for(i=1;i<=n;i++)
		cout<<s1[i]<<" ";
	 cout<<endl;
}
int main()
{freopen("triunghi.in","r",stdin);
 freopen("triunghi.out","w",stdout);
citire();
sol();
afis();
 
return 0;
}
