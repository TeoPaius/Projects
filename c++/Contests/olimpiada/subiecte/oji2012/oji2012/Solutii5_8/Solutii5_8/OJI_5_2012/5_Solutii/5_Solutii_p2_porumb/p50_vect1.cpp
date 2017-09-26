#include <fstream>
using namespace std;
char v[2060000];  //2097152 maximum de componente  de tip char pentru 2MB memorie totala
int main()
{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int n,x,k=0,t=0,p,tr=0,u=0,i;
    f>>n>>x;
    g<<(n+1)/2<<endl;
    while(k!=n)
    {
        p=1;t++;//cout<<endl;
        for(i=1;i<=n;i++)
         if (v[i]==0)
          {   p++;
              if(p==2)
              {v[i]=1;p=0;
               k++; u=i;
               if(i==x)tr=t;
               }


           }
    }
    g<<t<<endl<<tr<<endl<<u<<endl;

}
