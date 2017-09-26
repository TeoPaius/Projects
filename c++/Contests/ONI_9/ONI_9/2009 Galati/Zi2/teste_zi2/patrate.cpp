#include <stdio.h>
#include <math.h>

#define FOR(i,s,d) for(i=(s);i<(d);++i)
#define nmax 100111

int n, A[nmax], B[nmax],C[nmax], p,a,b,c;

int test(int x)
{
  int i,j;
  FOR(i, 1, 10000)
  {
    if(x < i*i) break;
    j = int(sqrt(x - i * i));
    if(j*j + i*i != x) continue;
    a = i;
    b = j;
    return 1;
  }
  return 0;
}

int doit(int x)
{
  int i;
  FOR(i, 1, 1000)
    if(test(x + i * i))
    {
      c = i;
      return x + i * i;
    }
  return -1;
}

int main()
{
  int i,j,l,k;
  freopen("patrate.in","r",stdin);
  freopen("patrate.out","w",stdout);
  scanf("%d", &n);
  scanf("%d", &p);
  j = 2;
  A[0] = B[0] = 1;
  C[0] = 0;
  l = 1;
  FOR(i, 3, n + 1)
  {
    j = doit(j);
    A[l] = a ;
    B[l] = b ;
    C[l] = c ;
    l++;
  }
  printf("%d\n", j);
  FOR(i,p,n+1)
  {
    k = n - i;
    printf("%d %d",A[k],B[k]);
    FOR(j,k+1, l) printf(" %d",C[j]);
    printf("\n");
  }
  return 0;
}
