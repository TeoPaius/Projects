#include<iostream>
using namespace std;

short int n,h[102],H,i;
int s,k,poz,gasit,val;
int cmp(const void *p,const void *q)
{return *(short int *)p - *(short int *) q;
}

int rez()
{
k=1;
do
 {	
  
 for(i=1;i<=k;i++)
	{h[i]=1+h[i];
      if(h[i]==H) return k-1;
	}
 
	val=h[k+1];	
  poz=k+1;
  while(val==h[poz] && poz<=n)
   { i=poz-1;gasit=0;
      while(i>=1 && !gasit)
		   if(val<h[i])
			   {h[i+1]=h[i];
		        i--;
			   }
	       else gasit=1;
	  h[i+1]=val;
	poz++;	   
   }
  k++;   
 }while(k<n);
return n;//nu e nevoie
}

int main()
{freopen("flori.in","r",stdin);
freopen("flori.out","w",stdout);

cin>>n>>H;
for(i=1;i<=n;i++)
	{cin>>h[i];
     s=s+h[i];
	}
cout<<s+n*(n+1)/2<<endl;
qsort(h+1,n,sizeof(h[0]),cmp);
cout<<rez();
return 0;
}
