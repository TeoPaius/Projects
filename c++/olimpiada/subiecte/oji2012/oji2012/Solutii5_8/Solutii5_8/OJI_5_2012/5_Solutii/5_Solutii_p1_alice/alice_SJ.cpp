//prof.Sanda Junea
#include <iostream>
#include<fstream>

using namespace std;

ifstream f("alice.in");
ofstream g("alice.out");
int magic(int x);

int n,k,nr,maxim,x;
int main(void) {
   f>>n>>k;
   for( int i = 0; i < n; ++i ) 
   {
		f>>x;
		if(x%2==0 && x>maxim)
			maxim=x;
		if(magic(x)==k)
			nr++;	
   }
   g<<maxim<<endl;
   g<<nr;
   f.close(); g.close();
   return 0;
}

int magic(int x)
{
	int y=x,m=0,l=x,r=1,zero=0,ok=1,z=x;
	if(x<10)
		return x;
	while(l>=10 && ok)
	{
		l=0;r=1,m=0;
		y=x;
		while(y)
		{
			if(y%10>m) 
				m=y%10;
			y=y/10;
		}
		y=x;
		while(y)
		{
			l=l+r*(m-y%10);
			r=r*10;
			y=y/10;
		}
		if(l==z)
			ok=0;
		else
		{
			ok=1;
			z=x;
			x=l;
		}
	}
	if(l<10)
		return l;
	else
		return -1;
}

