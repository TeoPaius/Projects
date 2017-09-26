//100 puncte Cristian Toncea
#include<fstream.h>
long a[100001];
int main()
{long long i,n,s,max=0,q=0;
ifstream f("deal.in");
ofstream g("deal.out");
f>>n;
for(i=1;i<=n;i++)
{f>>s;a[s]++;
if (a[s]>n/2)q=s;
if(s>max)max=s;}
i=max;
s=0;
if(q==0)
n=n/2;
else
	   if (a[q]-n/2>1)
		   n=n-a[q]+1;
	   else
		   n=n-a[q];
while(n>a[i])
	{s+=i*a[i];
n=n-a[i];i--;}
s+=i*n;
g<<s;
f.close();
g.close();}