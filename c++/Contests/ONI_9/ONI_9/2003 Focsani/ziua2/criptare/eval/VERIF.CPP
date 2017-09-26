#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OkFile "criptare.ok"
#define OutFile "criptare.out"
#define MAXN 1001

ofstream pct("criptare.pct",ios::app);

char ok[1001], out[1001];

void eror(int p, char *s)
{
  printf("%d %s\n", p, s);
  pct<<p<<endl;
  exit(0);
}

int main( void )
{
  ifstream fin(OkFile);
  fin.getline(ok, MAXN);
  fin.close();

  ifstream fout(OutFile);
  if (!fout) eror(0, "Fisier de iesire inexistent");
  fout.getline(out, MAXN);
  fout.close();

  if (strcmp(ok, out)) eror(0, "Decodificare incorecta");

  eror(10, "Corect");
  return 0;
}
