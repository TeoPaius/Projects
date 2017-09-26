//prof. Cristina Sichim
#include <fstream>
using namespace std;
ifstream f("alice.in");
ofstream g("alice.out");
int i,n,x,m,k,nr;

int vm(int x)
{int cmax=0,u=0;
 while(x){ if(x%10>cmax) cmax=x%10;
           x=x/10;
           u=u*10+1;}
 return u*cmax;
}
int complement(int x)
{ int nr=0,u;
  while(x>9 && nr<9)
  { u=vm(x);
    x=u-x;
	nr++;
  }
 if(x>9)return -1;
 return x;
}

int main()
{ f>>n>>k;
  while(n--){f>>x;
             if(x%2==0 && x>m)m=x;
             if(complement(x)==k)nr++;
            }   
g<<m<<'\n'<<nr<<'\n';
f.close();g.close();
return 0;
}
