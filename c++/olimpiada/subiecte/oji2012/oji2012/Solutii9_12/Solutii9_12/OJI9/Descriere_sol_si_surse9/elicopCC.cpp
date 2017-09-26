// sursa de 100 p Chesca Ciprian

#include <fstream>
#define nmax 101
#define kmax 41

using namespace std;

short modul(short x)
{
	if (x<0) return -x;
		else return x;
}	

short max(short x,short y)
{
	if (x>=y) return x;
		else return y;
}

short min(short x,short y)
{
	if (x>=y) return y;
		else return x;
}

int main()
{
short t[nmax][nmax],sol[nmax],m,n,k,x1,y1,x2,y2,v,i,j,pg,ne=0,l,c,tip,d;	

ifstream f("elicop.in");
ofstream g("elicop.out");

//initializez vectorul de solutii
for(i=0;i<kmax;i++) sol[i]=0;

// citesc datele de intrare
f>>m>>n;
for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		f>>t[i][j];
f>>k;

for(i=1;i<=k;i++)
	{
	 f>>x1>>y1>>x2>>y2>>v;
	 d=(x2-x1)*(y2-y1);
	 if (d>0&&v==-1) tip=1;
	 if (d>0&&v==1)  tip=2;
	 if (d<0&&v==1)  tip=3;
	 if (d<0&&v==-1) tip=4;
	 pg=0;
	 switch (tip)
		 {
		 case 1 :	{for(l=1;l<=max(x1,x2)-min(x1,x2)+1;l++)
						 for(c=1;c<=l;c++)
							 if (t[l+min(x1,x2)-1][c+min(y1,y2)-1]==0) pg++;
					 break;
					 }
		 case 2 :	{for(l=1;l<=max(x1,x2)-min(x1,x2)+1;l++)
						 for(c=l;c<=max(y1,y2)-min(y1,y2)+1;c++)
							 if (t[l+min(x1,x2)-1][c+min(y1,y2)-1]==0) pg++;
					break;	 
					}
		 case 3 :	{for(l=1;l<=max(x1,x2)-min(x1,x2)+1;l++)
						 for(c=1;c<=modul(x2-x1)+2-l;c++)
							 	 if (t[l+min(x1,x2)-1][c+min(y1,y2)-1]==0) pg++;
					break;	 
					}
		 case 4 :	{for(l=1;l<=max(x1,x2)-min(x1,x2)+1;l++)
						 for(c=modul(x2-x1)+2-l;c<=max(y1,y2)-min(y1,y2)+1;c++)
							 if (t[l+min(x1,x2)-1][c+min(y1,y2)-1]==0) pg++;
					break;	 
					}	 
		 }
	if (pg==0) ne++;
		else
			if (pg>(modul(x2-x1)+1)*(modul(x2-x1)+2)/4) sol[++sol[0]]=i;
	
	}
g<<ne<<"\n";
g<<sol[0]<<" ";
for(i=1;i<=sol[0];i++) g<<sol[i]<<" ";

f.close();
g.close();
return 0;
}	
