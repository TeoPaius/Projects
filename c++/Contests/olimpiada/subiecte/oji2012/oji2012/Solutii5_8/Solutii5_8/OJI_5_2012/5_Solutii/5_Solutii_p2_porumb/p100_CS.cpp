//autor. prof Cristina Sichim
# include <fstream>
using namespace std;

long n,m,x,nr;
int main()
{ifstream f("porumb.in");
 ofstream g("porumb.out");

 f>>n>>x;
 //a) nr.porumbi la prima trecere
 g<<(n+1)/2<<'\n';
 //b) nr trasee
 m=n;
 while(m>0)nr++,m=m/2;
 g<<nr<<'\n';
 //c)cand culege porumbul x
 while(x%2==0) x=x/2,m++;
 g<<m+1<<'\n';
//d) ultimul porumb
 m=1;
 while(m*2<=n)m=m*2;
 g<<m<<'\n';
 f.close();g.close();
return 0;
}
