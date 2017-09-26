#include <stdio.h>

#define MAXD 10001
#define MAXP 252

struct Detinut              //detinut
	 {
	   unsigned char NrOrd;              //numarul de ordine
	   unsigned char min, max; //pretentie
	   unsigned char NrP;      //paznicul care il pazeste
	 }D[MAXD];
struct MinMax                //zona unde pazeste paznicul i
	 {
	   unsigned char min, max;
	 }P[MAXP];               //posibil MAXP Paznici

int NrPaznici, N;

FILE* Fisier;




void Afiseaza(void)
{
  int i, j;

  Fisier=fopen("sant.out", "wt");
  fprintf(Fisier, "%d\n", NrPaznici);
  for (i=1; i<=NrPaznici; i++)
	{
	  fprintf(Fisier, "%d %d %d\n", i, P[i].min, P[i].max);
	  for(j=1;j<=N;j++)
	       if(D[j].NrP==i)
		fprintf(Fisier, "%d ", D[j].NrOrd);
	  fprintf(Fisier, "\n");
	}
  fclose(Fisier);
}

void Citeste(void)
{
  int i;

  Fisier=fopen("sant.in", "rt");
  fscanf(Fisier, "%d", &N);
  for (i=1; i<=N; i++)
	{
	  fscanf(Fisier, "%d %d", &D[i].min, &D[i].max);
	  D[i].NrOrd=i;
	}
  fclose(Fisier);
}


int Cauta(unsigned char min, unsigned char max)
{
  int i, Unde=-1;

  for (i=1; i<= NrPaznici; i++)
	{
	  if ((P[i].max>=min) && (P[i].max<=max)) Unde=i;//am gasit Paznicul i
	  if ((P[i].min>=min) && (P[i].min<=max)) Unde=i;//am gasit Paznicul i
	  if ((P[i].min<=min) && (P[i].max>=max)) Unde=i;//am gasit Paznicul i
	}
  return Unde;
}

unsigned char Maxim(unsigned char x, unsigned char y)
{
  if (x>y) return x;
  return y;
}

unsigned char Minim(unsigned char x, unsigned char y)
{
  if (x<y) return x;
  return y;
}


void Intersectie(int j, unsigned char min, unsigned char max)
{
  P[j].min=Maxim(min, P[j].min);//modific kilometrul minim unde pazeste
  P[j].max=Minim(max, P[j].max);//modific kilometrul maxim unde pazeste
}


void PunePaznici(void)
{
  int i, j;
  unsigned char min, max;

  P[1].min=D[1].min; P[1].max=D[1].max;
  NrPaznici=1; D[1].NrP=NrPaznici;
  for (i=2; i<= N; i++)          //pentru toti ceilalti detinuti
	{
	  min=D[i].min; max=D[i].max;
	  j=Cauta(min, max);  //caut un Paznic care mai pazeste detinuti
	  if (j>0)            //daca gasesc
		{
		  Intersectie(j, min, max);//ajustez kilometri din Paznic ca sa
		  D[i].NrP=j;	   //pazeasca si noul detinut
		}
	  else                //altfel
		{
		  NrPaznici++;             //iau un Paznic nou
		  P[NrPaznici].min=min;
		  P[NrPaznici].max=max;
		  D[i].NrP=NrPaznici;      //si ii dau in grija detinutul
		}
	}
}


int main()
{
  Citeste();
  PunePaznici();
  Afiseaza();
  return 0;
}
