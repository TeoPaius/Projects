#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OkFile "circular.ok"
#define OutFile "circular.out"

ofstream pct("circular.pct",ios::app);

unsigned long ok_cate, ok_max, out_cate, out_max, puncte;

void eror(int p, char *s)
{
  printf("%d %s\n", p, s);
  pct<<p<<endl;
  exit(0);
}

int main( void )
{
  ifstream fin(OkFile);
  fin>>ok_cate>>ok_max;
  fin.close();

  ifstream fout(OutFile);
  if (!fout) eror(0, "Fisier de iesire inexistent");
  fout>>out_cate>>out_max;
  fout.close();

  if (ok_cate==out_cate) puncte+=5;
  if (ok_max==out_max) puncte+=5;

  if (puncte!=10)
    if (ok_cate!=out_cate) eror(puncte, "Numere circulare gasite incorect");
  else
    if (ok_max!=out_max) eror(puncte, "Numarul circular maxim gasit incorect");

  eror(10, "Corect");
  return 0;
}
