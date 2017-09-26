//prof.Adriana Simulescu
#include<iostream>
#include<fstream>

using namespace std;

int main()
{ofstream out("porumb.out");
 ifstream in("porumb.in");
 int p=1,n,na=1,x,randx;
 in>>n>>x;
 out<<(n+1)/2<<endl;
 while(p<n)
 {p=p*2;
  na++;
  if((x-p)%(p*2)==0) randx= na;
 }
 if(p>n) {p=p/2;na--;}

 if(x%2==1) randx=1;
 out<<na<<endl<<randx<<endl<<p<<endl;
 in.close();
 out.close();
 return 0;
}
