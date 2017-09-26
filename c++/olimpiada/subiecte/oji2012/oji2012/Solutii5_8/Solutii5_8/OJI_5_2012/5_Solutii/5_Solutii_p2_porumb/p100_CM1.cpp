//prof.Carmen Minca
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int n,x,pas=1,t=0,tx=0,u=0,k=0,m;
    f>>n>>x;
    g<<(n+1)/2<<endl;
    m=n;
    while(k!=m)
    {   t++;   //o noua trecere
        k=k+(n+1)/2; //nr.porumbi culesi=nr de nr impare <=n
                     //sirul: pas(1,2,3,4,5,6,7), pas=2^(t-1)
        u=n*pas;
        if(n%2==0) u-=pas;
        if(x%pas==0)tx=t;
        n/=2; pas*=2;
    }
    if(x%2)tx=1;
    g<<t<<endl<<tx<<endl<<u<<endl;

}
