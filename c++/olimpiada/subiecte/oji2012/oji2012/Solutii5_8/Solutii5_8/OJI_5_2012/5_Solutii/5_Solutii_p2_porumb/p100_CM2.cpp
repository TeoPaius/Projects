//prof. Carmen Mica - o altfel de solutie 
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ifstream f("porumb.in");
    ofstream g("porumb.out");
    int n,x,a,t,ult,u;

    f>>n>>x;
    g<<(n+1)/2<<endl;
    u=log10(n*1.0)/log10(2.);  //u<--log2(n)
    a=u+1;                //a<--2^(u+1)
    ult=pow(2.0,u);       //ult<--2^u
    t=1;
    while(x%2==0){t++; x>>=1;}
         // x este pe randul care incepe cu
	 // 2^(t-1), t=maximum cu aceasta proprietate
    g<<a<<endl<<t<<endl<<ult<<endl;
    return 0;
}
