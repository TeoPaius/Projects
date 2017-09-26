//Adrian Pintea
#include <fstream>
//#include <iostream>
using namespace std;
ifstream fin("triunghi.in");
ofstream fout("triunghi.out");
long long a[1001][1001],p[1001],x,i,j,n;

int citire()
{
	fin >> n;
	for (i=n;i>0;i--) { fin>>p[i]>>x; a[i][p[i]]=x;}
	fin.close();

	//for (i = 1; i <= n; i++)
	//{
    //for (j = 1; j <= i; j++)
	//cout << a[i][j] << ' ';
	//cout << '\n';
	//}
	return 0;
}

//matricea de sus in jos
int construire()
{
	for (i = 2; i <= n; i++)
	{
	    if(p[i]>1)
	    { for(j=p[i]-1;j>0;j--) a[i][j]=a[i-1][j]-a[i][j+1];
          for(j=p[i];j<=i;j++) a[i][j]=a[i-1][j-1]-a[i][j-1];
	    } else for(j=p[i]+1;j<=i;j++) a[i][j]=a[i-1][j-1]-a[i][j-1];
	}

	//for (i = 1; i <= n; i++)
	//{
	//for (j = 1; j <= i; j++)
	//        cout << a[i][j] << ' ';
	// cout << '\n';
	// }

	return 0;
}

int afisare()
{
	  for (j = 1; j <= n; j++)
	         fout << a[n][j] << ' ';
	return 0;
}

int main()
{
	citire();
	construire();
	afisare();
	fout.close();
	return 0;
}
