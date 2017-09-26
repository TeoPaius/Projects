//Marcu Ovidiu
#include<iostream>
using namespace std;
int a[1001],b[1001],m,n,i,j,s;
int cmp1(const void *p,const void *q)
{ int x=*(int *)p;
  int y=*(int *)q;
  //return x-y;
  if(x>=y) return +1;
  else return -1;
}
int cmp2(const void *p,const void *q)
{ int x=*(int *)p;
  int y=*(int *)q;
  //return x-y;
  if(x>=y) return -1;
  else return +1;
}

void afis(int x[1001],int k){int j;for(j=1;j<=k;j++)cout<<x[j]<<" "; cout<<endl;}
int main()
{freopen("arme.in","r",stdin);
 freopen("arme.out","w",stdout);
cin>>n>>m;
for(i=1;i<=n;i++) {cin>>a[i];s=s+a[i];}
for(i=1;i<=m;i++) cin>>b[i];
  qsort(a+1,n,sizeof(a[0]),cmp1);//a crescator
  qsort(b+1,m,sizeof(b[0]),cmp2);//b descrescator
//afis(a,n);afis(b,m);
  
int k=n;
 if(m<n)k=m;
i=1;
while(i<=k && a[i]<b[i])
   {s=s+(b[i]-a[i]);
    i++;
   }
   
cout<<s;   
return 0;
}
