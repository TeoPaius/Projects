// Autor: Mihai Scortaru

#include <stdio.h>

char a[200][200]; // matricea
long nr[201]; // vectorul cu frecventele aparitiei blocurilor
	     // nr[i] - numarul blocurilor de lungime i necesare
int m, n; // dimensiunile matricei;

void CitesteDate(void){
  FILE *f=fopen("PENTAGON.IN","rt");
  fscanf(f,"%d%d%*c",&m,&n); // citirea dimensiunilor si trecerea peste marcajul de sfarsit de linie
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++)
      fscanf(f,"%c",&a[i][j]);
    fscanf(f,"%*c"); // se trece peste marcajul de sfarsit de linie
  }
  fclose(f);
}

void DeterminaSolutia(void){
  int lung=0; //lungimea secventei
  for (int j=0;j<n;j++){
    for (int i=0;i<m;i++)
      if (a[i][j]=='0')
	lung++;  // incrementarea numarului de zerouri
      else{
	nr[lung]++; // sfarsitul secventei datorita aparitiei unui 1
		    // exista posibilitatea sa se incrementeze nr[0] daca lung este 0
		    // aceasta nu afecteaza corectitudinea implementarii deoarece la afisare blocurile de dimensiune 0 nu sunt luate in condiderare
	lung=0;
      }
    nr[lung]++; // sfarsitul secventei datorita terminarii coloanei
    lung = 0;
  }
}

void ScrieSolutia(void){
  FILE *f=fopen("PENTAGON.OUT","wt");
  for (int i=1;i<=m;i++)
    if (nr[i]) // exista blocuri de lungime i
      fprintf(f,"%d %d\n",i,nr[i]);
  fclose(f);
}

int main(void){
  CitesteDate();
  DeterminaSolutia();
  ScrieSolutia();
}
