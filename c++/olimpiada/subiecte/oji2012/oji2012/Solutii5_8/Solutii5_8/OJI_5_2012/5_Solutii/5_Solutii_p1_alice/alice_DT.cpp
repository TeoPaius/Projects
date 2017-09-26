//prof. Daniela Tarasa
#include<fstream.h>
ifstream f("alice.in");
ofstream g("alice.out");
int n,k,x,nr,par,max_par;
int main()
{int y1,y2,y3,z,max,p,ok;
	f>>n>>k;
for(int i=1;i<=n;i++)
{f>>x;y2=y3=-1;
if(x%2==0 && max_par<x) max_par=x;
	y1=x;ok=1;z=x;
	while(x>9&&ok)
		{max=0;p=1;
			while(z!=0){if(max<z%10) max=z%10;z=z/10;}
			while(x!=0){z=z+(max-x%10)*p;p=p*10;x=x/10;}
		if(z==y1||z==y3) ok=0;
		x=z;y3=y2;y2=z;
		}
if (ok&&x==k) nr++;
	}
g<<max_par<<'\n'<<nr<<'\n';
f.close();
g.close();
return 0;
	}



