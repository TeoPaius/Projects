// sursa Liliana Schiopu

#include<fstream.h>
ifstream f("culori.in");
ofstream g("culori.out");
int n,i,A[10000];
unsigned long long nr=1;
void mul(int A[], int B)
{
int i, t = 0;
for (i = 1; i <= A[0] || t; i++, t /= 10)
A[i] = (t += A[i] * B) % 10;
A[0] = i - 1;
}
int main()
{f>>n;
 if(n==1)g<<5;
 else if(n==2)g<<8;
  else if(n==3)g<<14;
    else if(n%2==0)
		  {A[1]=8;
		   A[0]=1;
			for(i=1;i<=(n-2)/2;i++)
				mul(A,3);
			for(i=A[0];i>=1;i--)
				g<<A[i];
		   }

       else if(n%2!=0)
		   {A[1]=14;
		   A[0]=1;
			for(i=1;i<=(n-3)/2;i++)
				mul(A,3);
			for(i=A[0];i>=1;i--)
				g<<A[i];
		   }
  f.close();
  g.close();
return 0;
}