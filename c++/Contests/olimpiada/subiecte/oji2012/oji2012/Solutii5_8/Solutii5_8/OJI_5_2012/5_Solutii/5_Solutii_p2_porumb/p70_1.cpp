#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int n,x,p=1,pas=1,t=0,tx=0,u=0,i,k=0,m;
    f>>n>>x;
    g<<(n+1)/2<<endl;
    m=n;
    while(k!=m)
    {   t++;
        for(i=1;i<=n;i=i+2)
         {
             k++;u=i*pas;
	 }
         if(n%2)n--;
         if(x%pas==0)tx=t;
         n/=2; pas*=2;
    }
    if(x%2)tx=1;
    g<<t<<endl<<tx<<endl<<u<<endl;

}
