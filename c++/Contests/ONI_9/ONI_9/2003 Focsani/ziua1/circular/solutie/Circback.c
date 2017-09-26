#include <stdio.h>

FILE *f, *g;

unsigned long N, nn, n, contor, gata, nc1, NCircM, y;
int c[100], vc[11], i, nc, x[10], uz[10], c1, cifra;

int CIRC(void)
{
  int i, j, k, CORECT;

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

void prelucreaza(void)
{
  int i;
  for (i=1; i<=n; i++) c[i]=x[i];
  nc=n;
  if (CIRC())
    {
      y=0;                               //formez numarul
      for (i=1; i<=n; i++) y=y*10+x[i];
      if (!gata)                         //
	{
	  contor++;
	  NCircM=y;
	}
      else
	if (y<=N)
	 {
	   contor++;
	   NCircM=y;
	 }

    }
}

void back(int k)
{
  int i;
  if (k==n+1)
    prelucreaza();
  else
    for (i=1; i<=9; i++)
      if (!uz[i])
	{
	  uz[i]=1;
	  x[k]=i;
	  back(k+1);
	  uz[i]=0;
	}
}

int main(void)
{
  f=fopen("circular.in", "rt");
  g=fopen("circular.out", "wt");
  fscanf(f, "%U", &N); fclose(f);
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
  nc1=nc;
  c1=c[1]; gata=0;
  contor=0;
  for (n=2; n<nc1; n++) back(1);
  gata=1;
  for (cifra=1; cifra<=c1; cifra++)
    {
      x[1]=cifra;
      uz[cifra]=1;
      back(2);
      uz[cifra]=0;
    }

  fprintf(g, "%ld %ld\n", contor, NCircM);
  fclose(g);

  return 0;
}
