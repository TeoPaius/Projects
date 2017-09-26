//prof. Jakab Irma Tunde
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <math.h>
int main(void)
{unsigned long n,x,p=1,e=0,a,b;
 fstream f,g;
 f.open("porumb.in", ios::in);
 f>>n>>x;
 while (p*2<n){
	p*=2;
	e++;
 }
 if (x%2)b=1;
 else{
	  a=p;b=0;
	  while (x%a!=0){
		a/=2;
		b++;
	  }
	}
 cout<<e+1<<' '<<e+1-b<<' '<<p;
 g.open("porumb.out", ios::out);
 g<<(n+1)/2<<endl<<e+1<<endl<<e+1-b<<endl<<p;;
 g.close();
}
