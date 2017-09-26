//Pintea Adrian
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("arme.in");
ofstream fout("arme.out");

int n,m,i,j,p[2001],aux,rezultat;

int main(){
fin>>n>>m;
for(i=0;i<n;i++)
	fin>>p[i];
for(i=n;i<n+m;i++)
	fin>>p[i];
rezultat=0;
for(i=0;i<n;i++) {
	for(j=i+1;j<n+m;j++) {
		if (p[i]<p[j]) {
			aux=p[i];
			p[i]=p[j];
			p[j]=aux;
		}
	}
	rezultat+=p[i];
}
fout<<rezultat<<"\n";
fout.close();
return 0;
}
