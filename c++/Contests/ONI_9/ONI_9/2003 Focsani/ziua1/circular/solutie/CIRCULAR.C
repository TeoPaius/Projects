#include <stdio.h>

FILE *f, *g;

unsigned long N, nn, CircM, contor=0;
int c[100], vc[11], i, circular, nc;

int CIRC(void)
{
  int i, j, k, CORECT;

  for (i=1; i<=nc; i++)
    if (!c[i]) return 0;        //cifre nenule
  for (i=1; i<=nc; i++)
    for (j=i+1; j<=nc; j++)
      if (c[i]==c[j]) return 0; //numarul nu are cifre distincte
  for (i=1; i<=nc; i++)
    for (j=1; j<=10; j++)         //pun numarul de 10 ori in vector
      c[j*nc+i]=c[i];
  for (i=0; i<11; i++) vc[i]=0;   //vectorul caracteristic pe 0
  i=1; vc[1]=1; CORECT=1; j=1;    //initializari
  while (CORECT)                  //parcurg cifrele pana gasesc una de 2 ori
    {
      k=1;
      while (k<=c[i])
	{
	  j++;
	  k++;
	}
      if (j%nc==0)                //sunt chiar pe ultima cifra
	k=nc;
      else
	k=j%nc;                   //sunt pe o cifra distincta de ultima
      vc[k]++;                    //marchez in vectorul caracteristic
      if (vc[k]>1) CORECT=0;      //am ajuns aici a doua oara
      i=k;                        //noua cifra
    }
  for (i=2; i<=nc; i++)   //am "trecut" prin toate cifrele? sau
    if ((!vc[i])||(vc[i]>1))//ciclul s-a incheiat la alta cifra decat prima?
      return 0;
  return 1;               //este OK!!!
}

int main()
{
  f=fopen("circular.in", "rt");
  fscanf(f, "%U", &N); fclose(f);
  CircM=0;
  while (N>10)
    {
      nn=N;
      nc=0;
      while (nn)   //determin numarul de cifre
	{
	  nc++;
	  nn/=10;
	}
      nn=N;
      for (i=nc; i>=1; i--) //pun cifrele in vector corect
	{                       //Obs. daca un numar este circular
	  c[i]=nn%10;           //     nu rezulta ca inversul este
	  nn/=10;		    //     si el circular
	}
      if (CIRC())
	{
	  contor++;
	  if (N>CircM) CircM=N;
	}
      N--;
    }
  g=fopen("circular.out", "wt");
  fprintf(g, "%ld %ld\n", contor, CircM);
  fclose(g);
  return 0;
}