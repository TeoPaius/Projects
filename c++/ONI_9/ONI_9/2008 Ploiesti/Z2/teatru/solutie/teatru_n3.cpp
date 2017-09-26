#include <stdio.h>

char  s[55001];
long imax, jmax, Lmax, n, k;
long f[91];

void Citeste();
void Afis();
void Calculeaza();

int main()
{
   freopen("teatru.in", "r", stdin);
   freopen("teatru.out", "w", stdout);
   Citeste();
   Calculeaza();
   Afis();
   return 0;
}

void Citeste()
{
   scanf("%d%d", &n, &k); 
   scanf("%c", &s[0]);      // citeste '\n'
   for (long int i = 0; i < n; i++ )
		scanf("%c", s + i);
}
      
void Afis()
{
   printf("%d\n", Lmax);
   for (long int i = imax; i <= jmax; i++ )
      printf("%c", s[i]);
   printf("\n");
}

void Calculeaza()
{
   long int i = 0, j = 0, nr = 0, p;
   
   for (  i = 0; i < n; i++ )
      for ( j = i; j < n; j++ )
      {
          for ( p = 'A'; p <= 'Z'; p++ )
             f[p] = 0;                        
          for ( p = i; p <= j; p++ )
             f[s[p]] = 1;   
          nr = 0;                     
          for ( p = 'A'; p <= 'Z'; p++ )
             if ( f[p] ) nr++;
             
          if ( nr == k && Lmax < j - i + 1)
          {
             Lmax = j - i + 1;          
             imax = i; jmax = j;
          }   
      }   
}


