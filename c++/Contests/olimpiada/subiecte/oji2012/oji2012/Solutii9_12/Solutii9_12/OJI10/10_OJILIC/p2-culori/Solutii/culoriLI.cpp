#include <fstream>
using namespace std;
typedef struct{int nrc;int c[2001];} NUMAR;
ifstream fi("culori.in");
ofstream fo("culori.out");
int n,i;
NUMAR W1,W2,R1,R2,B1,B2,G1,G2,Y1,Y2;
NUMAR rez,X;
void initializare(NUMAR &X)
{
	int i;
	for (i=1;i<=2000;i++)
		X.c[i]=0;
	X.c[1]=1;
	X.nrc=1;
}
void suma(NUMAR A, NUMAR B, NUMAR &C)
{
	int s,i,t;
	t=0;
	initializare(C);
	C.c[1]=0;
	for (i=1;i<=2000;i++)
	{
		s=t+A.c[i]+B.c[i];
		C.c[i]=s%10;
		t=s/10;
	}
	i=2000;
	while (C.c[i]==0)
		i--;
	C.nrc=i;
}

void scrie(NUMAR X)
{
	int i;
	//fo<<X.nrc<<"\n";
	for (i=X.nrc;i>=1;i--)
		fo<<X.c[i];
	fo<<"\n";
}

int main()
{
	fi>>n;
	initializare(W1);
	initializare(R1);
	initializare(B1);
	initializare(G1);
	initializare(Y1);
	for (i=2;i<=n;i++)
	{
		W2=B1;
		suma(G1,B1,R2);
		suma(W1,R1,B2);
		suma(R1,Y1,G2);
		Y2=G1;
		
		W1=W2;
		R1=R2;
		B1=B2;
		G1=G2;
		Y1=Y2;
	}
	suma(W1,R1,rez);
	X=rez;
	suma(X,B1,rez);
	X=rez;
	suma(X,G1,rez);
	X=rez;
	suma(X,Y1,rez);
	scrie(rez);
	fi.close();
	fo.close();
	return 0;
}
