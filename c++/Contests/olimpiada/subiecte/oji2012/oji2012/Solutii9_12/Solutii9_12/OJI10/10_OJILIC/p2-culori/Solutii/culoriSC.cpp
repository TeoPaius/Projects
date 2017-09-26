// Sura prof. Silviu Candale
#include <fstream>
#include <iostream>
#include <cassert>
#define BAZA 100000000
#define NRC 8
//pentru debug
//#define TOATE true
//end of debug



using namespace std;

ifstream fin ("culori.in" );
ofstream fout("culori.out");

typedef int NrMare[5000];

int n; 

NrMare x;

void Atrib(NrMare x, int a){
	x[0] = 0;
	while(a){
		x[++x[0]] = a % BAZA;
		a /= BAZA;
	}
}

int NrCif(int n){
	if( n<10 )
		return 1;
	int r = 0 ;
	while( n )
		++r, n /= 10;
	return r;
}

void Produs(NrMare x, int n){
	int t=0, tmp;
	for(int i=1;i<=x[0];++i){
		tmp = x[i]*n+t;
		x[i] = tmp % BAZA;
		t = tmp /BAZA;
	}
	while(t)
		x [ ++x[0] ] = t % BAZA, t /= BAZA;
}

void Afis(ostream &out, NrMare x){
	out << x[ x[0] ];
	for(int i = x[0]-1 ; i ; --i)
	{
		int p = BAZA;
		while(p/10>x[i])
			out  << 0, p /= 10;
		out << x[i] ;
	}
	out << endl;
}

int main(){
	fin >> n;
	assert( 0 < n && n < 5001 );
	#ifdef TOATE
	for(int m = 1 ; m<=5000 ; ++m){
		cout << m << endl;
		n = m;
	#endif
	if(n==1){
		Atrib(x,5);
	}
	else{
		if(n%2==1)
			Atrib(x,14), n--;
		else
			Atrib(x,8);
		n = n/2 - 1;
		for(; n ; --n)
			Produs(x,3);
	}
	Afis(fout,x);
	#ifdef TOATE
	}
	#endif
	return 0;
}

