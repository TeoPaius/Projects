//prof. Adriana Simulescu
#include <fstream>

using namespace std;
ifstream fin("alice.in");
ofstream fout("alice.out");
int main()
{int n,k,x,nmax,ncif,nmaxpar=-1,y,cifmax,nr_trans,i,j,nr=0;
fin>>n>>k;
for(i=1;i<=n;i++)
{ fin>>x;
  if(x%2==0&&x>nmaxpar) nmaxpar=x;
  nr_trans=0;
  do{
	  y=x;
	  ncif=0; cifmax=0;
	  while(y)
		  {if(y%10>cifmax) cifmax=y%10;
		   ncif++;
		   y=y/10;
		  }
	  nmax=0;
	  for(j=1;j<=ncif;j++)
		  nmax=nmax*10+cifmax;
	  x=nmax-x;
	  nr_trans++;
  } while(x>9&&nr_trans<20);
  if(x==k) nr++;
  
}
fout<<nmaxpar<<endl<<nr<<endl;
fin.close();
fout.close();
}
