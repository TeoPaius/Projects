#include <stdio.h>

#define MAXD 10001
#define MAXP 252

struct Detinut              //detinut
	 {
	   int NrOrd;              //numarul de ordine
	   unsigned char min, max; //pretentie
	   unsigned char NrP;      //paznicul care il pazeste
	 }D[MAXD];

struct MinMax                //zona unde pazeste paznicul i
	 {
	   unsigned char min, max;
	 }P[MAXP];               //posibil MAXP Paznici

int NrPaznici, N;

FILE* Fisier;

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

int Cauta(unsigned char min, unsigned char max)
{
  int i, Unde;

  for (i=1; i<= NrPaznici; i++)
	{
	  if ((P[i].max>=min) && (P[i].max<=max)) Unde=i;//am gasit Paznicul i
	  if ((P[i].min>=min) && (P[i].min<=max)) Unde=i;//am gasit Paznicul i
	  if ((P[i].min<=min) && (P[i].max>=max)) Unde=i;//am gasit Paznicul i
	  if ((P[i].max<min) || (P[i].min>max)) Unde=-1; //nu am gasit Paznic
	}
  return Unde;
}

void Intersectie(int j, unsigned char min, unsigned char max)
{
  P[j].min=Maxim(min, P[j].min);//modific kilometrul minim unde pazeste
  P[j].max=Minim(max, P[j].max);//modific kilometrul maxim unde pazeste
}

void Ordoneaza(void)
{                      //sortare prin selectie
  int i, j, pKMmin;
  unsigned char KMmax, KMmin;
  struct Detinut Aux;

  for (i=1; i<=N-1; i++)
	{
	  KMmin=D[i].min; KMmax=D[i].max; pKMmin=i;
	  for (j=i+1; j<=N; j++)
		if (D[j].min<KMmin)   //crescator dupa kilometrul minim
		  { KMmax=D[j].max; KMmin=D[j].min; pKMmin=j; }
		else
		  if (D[j].min==KMmin)//pentru kilometrul minim egal
			if (D[j].max>KMmax)     //descrescator dupa cel maxim
			  { KMmax=D[j].max; KMmin=D[j].min; pKMmin=j; }
	  Aux=D[pKMmin]; D[pKMmin]=D[i]; D[i]=Aux;
	}
}

void Sorteaza(int p, int u)
{
  int i, j, pozm;
  int min;
  struct Detinut Aux;

  for (i=p; i<u; i++)
	{
	  min=D[i].NrOrd; pozm=i;
	  for (j=i+1; j<=u; j++)
	  if (D[j].NrOrd<min)
		{
		  min=D[j].NrOrd; pozm=j;
		}
	  Aux=D[i]; D[i]=D[pozm]; D[pozm]=Aux;
	}
}

void Citeste(void)
{
  int i, x, y;

  Fisier=fopen("sant.in", "rt");
  fscanf(Fisier, "%d", &N);
  for (i=1; i<=N; i++)
	{
	  fscanf(Fisier, "%d %d", &x, &y);
	  D[i].min=x; D[i].max=y;
	  D[i].NrOrd=i;
	}
  fclose(Fisier);
}

void PunePaznici(void)
{
  int i, j;
  char min, max;

  //pun primul detinut (deci cel cu intervalul cel mai mare sau)
  //la primul Paznic
  P[1].min=D[1].min; P[1].max=D[1].max;
  NrPaznici=1; D[1].NrP=NrPaznici;
  for (i=2; i<= N; i++)          //pentru toti ceilalti detinuti
	{
	  min=D[i].min; max=D[i].max;
	  j=Cauta(min, max);  //caut un Paznic care mai pazeste detinuti
	                      //si poate sa-l pazeasca si pe asta
	  if (j>0)            //daca gasesc
		{
		  Intersectie(j, min, max);//ajustez kilometri din Paznic ca sa
		  D[i].NrP=NrPaznici;	   //pazeasca si noul detinut
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

void Afiseaza(void)
{
  int i, j, p, u;

  Fisier=fopen("sant.out", "wt");
  fprintf(Fisier, "%d\n", NrPaznici);
  p=1; u=1;
  for (i=1; i<=NrPaznici; i++)
	{
	  fprintf(Fisier, "%d %d %d\n", i, P[i].min, P[i].max);
	  while (D[u].NrP==i&&u<=N) u++;
	  Sorteaza(p, u-1);
	  for (j=p; j<u-1; j++)
		fprintf(Fisier, "%d ", D[j].NrOrd);
	  fprintf(Fisier, "%d\n", D[u-1].NrOrd);
	  p=u;
	}
  fclose(Fisier);
}

int main(void)
{
  Citeste();
  Ordoneaza(); //ordonez intervalele de kilometri
			   //crescator dupa kilometrul minim si
			   //descrescator dupa kilometrul maxim
  PunePaznici();
  Afiseaza();
  return 0;
}
