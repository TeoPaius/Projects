//prof. Daniela Tarasa

#include<fstream.h>
#include<math.h>
ifstream f("porumb.in");
ofstream g("porumb.out");
int nr,n,x,nr1=1,aux;
long long q;
int main()
{f>>n>>x;
aux=x;
//numarul de porumbi culesi de primul agri
if(n%2==0) g<<n/2<<'\n';else g<<n/2+1<<'\n';
//numarul de agri
while(n!=0)
		{
			n=n/2;
			nr++;
		}
g<<nr<<'\n';
//numarul trecerii la care este cules porumbul x
	while(x%2==0)
		{
			x=x/2;
			nr1++;
		}
if (aux%2!=0) g<<1<<'\n';
	else g<<nr1<<'\n';

q=pow(2,nr-1);
g<<q<<'\n';
f.close();
g.close();
return 0;}
