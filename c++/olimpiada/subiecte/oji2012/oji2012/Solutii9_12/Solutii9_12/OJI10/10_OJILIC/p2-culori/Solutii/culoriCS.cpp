// sursa prof. Cristina Sichim
# include <fstream>
# define dim 2000
using namespace std;
ifstream fi("culori.in");
ofstream fo("culori.out");
int w[2][dim],b[2][dim],r[2][dim],g[2][dim],y[2][dim],lv,lc,i,n;

void copie(int v1[],int v2[])
{ for(int i=0;i<=v2[0];i++)v1[i]=v2[i];}

void suma(int rez[],int v1[], int v2[])
{ int i,t=0,u=v1[0];
  if(v2[0]>u)u=v2[0];
  for(i=1;i<=u;i++) rez[i]=(v1[i]+v2[i]+t)%10, t=(v1[i]+v2[i]+t)/10;
  if(t)rez[u+1]=t,rez[0]=u+1;
       else rez[0]=u;
}

void afis(int v[])
{ for(int i=v[0];i>=1;i--) fo<<v[i];
  fo<<'\n';
}
int main()
{ fi>>n;
  w[1][1]=w[1][0]=b[1][1]=b[1][0]=r[1][1]=r[1][0]=g[1][1]=g[1][0]=y[1][1]=y[1][0]=1;
  lv=1;
  for(i=2;i<=n;i++)
  {lc=1-lv;
   copie(w[lc],b[lv]);
   suma(b[lc],w[lv],r[lv]);  //b=w+r
   suma(r[lc],b[lv],g[lv]); //r=b+g
   suma(g[lc],r[lv],y[lv]);//g=r+y
   copie(y[lc],g[lv]);
   lv=lc;
  }
  lc=1-lv;
  suma(w[lc],w[lv],b[lv]);	
  suma(w[lv],w[lc],g[lv]); 
  suma(w[lc],w[lv],r[lv]); 
  suma(w[lv],w[lc],y[lv]); 
  for(i=w[lv][0];i>=1;i--) fo<<w[lv][i];
  fo<<'\n';
  fi.close();fo.close();
   return 0;
}