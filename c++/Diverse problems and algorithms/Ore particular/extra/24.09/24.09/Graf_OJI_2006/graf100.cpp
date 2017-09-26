#include <fstream.h>
const nmax = 7501;
struct node { int x; node * next;};
typedef int sir[nmax];
typedef node* nod;
nod v[nmax];
int *dx, *dy, *num, *vertex, *at, l[nmax];
int n,m,x,y,i,j,xx,yy,nr;
nod p;
ifstream fi("graf.in");
void bfs (int x, int d[])
{ int tail, ttail, head, i;
  nod p,q;
  setmem(d,(n+1)*sizeof(int),0);
  head=1; tail=1; ttail=1;
  l[1]=x; d[x]=1;
  do
  { for (i=head; i<=tail; i++)
    {
     p = v[l[i]];
     while (p!=NULL)
      { if (d[p->x]==0)
	 { ttail++;
	   l[ttail] = p->x;
	   d[p->x] = d[l[i]]+1;
	  }
	  p = p->next;
       }
     }
    if (tail==ttail) break;
    head = tail+1;
    tail = ttail;
    }
  while (1);
}
void main()
{
 fi>>n>>m>>x>>y;
 for (i=1;i<=m;i++)
   { fi>>xx>>yy;
     p = new node;
     p->x = yy;
     p->next = v[xx];
     v[xx] = p;
     p = new node;
     p->x = xx;
     p->next = v[yy];
     v[yy] = p;
   }
 dx = new int[n+1];
 bfs(x, dx);
 dy = new int[n+1];
 bfs(y,dy);
 num = new int[n+1];
 for (i=0;i<=n;i++)
   num[i]=0;

 vertex = new int[n+1];
 for (i=0;i<=n;i++)
   vertex[i]=0;
 for (i=1;i<=n;i++)
   if (dx[i] + dy[i] == dx[y]+1)
     { num[dx[i]]++;
       vertex[dx[i]] = i;
     }
 at = new int[n+1];
 for (i=0;i<=n;i++)
   at[i]=0;
 nr = 0;
 for (i=1;i<=n;i++)
   if (num[i]==1)
     { nr++;
       at[vertex[i]]=1;
     }
 ofstream fo("graf.out");
 fo<<nr<<endl;
 for (i=1;i<=n;i++)
   if (at[i]==1)
    fo<<i<<' ';
}