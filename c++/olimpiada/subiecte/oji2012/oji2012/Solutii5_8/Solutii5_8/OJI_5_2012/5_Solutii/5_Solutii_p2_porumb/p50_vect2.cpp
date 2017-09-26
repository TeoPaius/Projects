// porumb pe vector
# include <fstream.h>
char p[2060000];
int n,x,agri,culesi,cand,u,i,culeg;
ifstream f("porumb.in");
ofstream g("porumb.out");
int main()
{f>>n>>x;
 g<<(n+1)/2<<'\n';
 while(culesi<n)
 {  agri++;
	culeg=1;
	for(i=1;i<=n;i++)
		if(p[i]==0)
			{if(culeg) {p[i]=1;if(i==x)cand=agri;culesi++;u=i;}
		     culeg=!culeg;
			}
 }
 g<<agri<<'\n'<<cand<<'\n'<<u<<'\n';
 f.close();g.close();
 return 0;
}
