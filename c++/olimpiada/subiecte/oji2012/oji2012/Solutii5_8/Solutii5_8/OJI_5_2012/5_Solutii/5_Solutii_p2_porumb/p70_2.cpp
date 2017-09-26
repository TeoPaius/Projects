#include <fstream>
#include <iostream>
using namespace std;
char v[2000000];
int main()
{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int n,x,p=1,pas=2,t=0,tx=0,u=0,i,k=0;
    f>>n>>x;
    g<<(n+1)/2<<endl;

    while(k!=n)
    {   t++;
        for(i=p;i<=n;i=i+pas)
         {
             k++;
             if(i==x)tx=t;
             u=i;
         }
         p=pas; pas=pas*2;
    }
    g<<t<<endl<<tx<<endl<<u<<endl;

}
