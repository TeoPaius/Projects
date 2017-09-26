#include<fstream.h>
#include<iostream.h>
int a[1001],n,m,t[401],s[401],v[401];
ifstream f("joc.in");
ofstream g("joc.out");

   int main()
   {int i,j,x,castigator=0,nrp=0,viz[1001],l[1001];
   long etapa,e_min=320000000,c_min,i_min;
    f>>n>>m;
    for(i=1;i<=n;i++)
      {
	for(j=1;j<=m;j++)
	   {f>>a[j];viz[j]=0;}

	etapa=1;
	j=1;viz[1]=1;
	castigator=0;
	while(!castigator&&t[i]!=-1)
	  {
	    x=a[j];
	    viz[j]=1;

	    if(x==0) {t[i]=-1;v[i]=etapa;}
	    else if(x==9999)
		      {if(etapa<e_min){c_min=i;e_min=etapa;i_min=j;}
		       castigator=1;
		      }
		 else {
			if(j==x/10) break;
			j=x/10;
			if(viz[j]==1) break;
			else etapa=etapa+x%10+1;
		      }
	    }
     }
    nrp=0;
    for(i=1;i<=n;i++)
       if(t[i]==-1&&v[i]<=e_min) nrp++;
    g<<c_min<<" "<<i_min<<" "<<e_min<<" "<<nrp<<endl;
    f.close();g.close();
    return 0;
    }



