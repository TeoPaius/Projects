#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OkFile "scaune.ok"
#define OutFile "scaune.out"
#define InFile "scaune.in"

ofstream pct("scaune.pct",ios::app);

int ok_loc, ok_poz, out_loc, out_poz, puncte, x, nc;

void eror(int p, char *s)
{
  printf("%d %s\n", p, s);
  pct<<p<<endl;
  exit(0);
}

int main( void )
{
  int i;
  ifstream fi(InFile);
  fi>>x>>nc;
  fi.close();

  ifstream fin(OkFile);

  ifstream fout(OutFile);
  if (!fout) eror(0, "Fisier de iesire inexistent");

  for(i=1;i<=nc;i++)
   {  fin>>ok_loc>>ok_poz;
      fout>>out_loc>>out_poz;
      if ((ok_loc==out_loc)&&(ok_poz==out_poz)) puncte++;
   }

  if (puncte!=nc) eror(puncte, "Numere asociate incorect");

  eror(10, "Corect");

  fin.close();
  fout.close();

  return 0;
}
