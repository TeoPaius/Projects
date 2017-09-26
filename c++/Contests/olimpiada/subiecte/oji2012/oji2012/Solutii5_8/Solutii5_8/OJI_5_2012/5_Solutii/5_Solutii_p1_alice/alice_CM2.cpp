//autor. prof. Carmen Minca
#include <fstream>

using namespace std;

int main()
{
    int x,cmax,c,z,nrmax,i,nc=0,a, maxpar=0,n,j,nr=0,k;
    ifstream f("alice.in");
    ofstream g("alice.out");
    f>>n>>k;
    for(j=1;j<=n; j++)
    {
         f>>a; z=x=a;
         if(a%2==0 && maxpar<a)maxpar=a;
         do {
                a=z; z=x; cmax=0;  nc=0;
                while(x)
                {
                    c=x%10; x=x/10;nc++;
                    if(c>cmax)cmax=c;
                }
                nrmax=0;
                for(i=1;i<=nc;i++)
                   nrmax=nrmax*10+cmax;
                x=nrmax-z;
            } while(x>9 && x!=z && x!=a);
        if(x==k) nr++;
    }
    g<<maxpar<<endl<<nr;
    return 0;
}
