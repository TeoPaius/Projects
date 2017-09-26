// Autor: Mihai Scortaru
// Copyright (c) 2002 Agora Media SRL
// Acest fisier este distribuit in regim freeware.
// Nu este permisa modificarea codului sursa fara acordul autorului.
// Acest fisier nu poate fi folosit in scopuri comerciale fara acordul
//   scris al SC Agora Media SRL.
// Acest fisier este distribuit "asa cum este"; autorul sau Agora Media SRL
//   nu pot fi responsabili pentru eventuale daune provocate direct sau
//   indirect de acest fisier.
// Programul a fost testat utilizand seturile de date folosite la ONI 2002
//   si a functionat corect in toate aceste situatii.

#include <stdio.h>
#include <math.h>

double r[1000]; // razele discurilor
double x[1000]; // coordonatele orizontale ale centrelor cercurilor
int dispensabil[1000]; // indica faptul ca un disc este sau nu dispensabil
int n; // numarul cercurilor
int k; // numarul cercurilor dispensabile
double latime; // latimea figurii
int ultimulDisc; // discul care contine punctul cel mai din dreapta al figurii

void CitesteDate(void){
  FILE *f=fopen("DISCURI.IN","rt");
  fscanf(f,"%d",&n);
  for (int i=0;i<n;i++)
    fscanf(f,"%lf",&r[i]);
  fclose(f);
}

inline double Coordonata(double x1, double r1, double r2){
  return x1 + sqrt((r1+r2)*(r1+r2)-(r1-r2)*(r1-r2));
}

void InsereazaCercul(int k){
  int cercAtins=0;
  x[k] = r[k]; // presupunem ca va atinge axa Oy -> coordonata orizontala va fi egala cu raza
  cercAtins = -1;
  for (int i=0;i<k;i++){
    double nouaCoordonata = Coordonata(x[i],r[i],r[k]);
    if (nouaCoordonata > x[k]){
      x[k] = nouaCoordonata; // cercul atins cel mai recent de k este i
      cercAtins = i;
    }
  }
  for (i = cercAtins + 1; i < k; i++)
    dispensabil[i] = 1;
  if (latime < x[k] + r[k]){
    latime = x[k] + r[k];
    ultimulDisc = k;
  }
}

void DeterminaSolutia(void){
  for (int i=0;i<n;i++)
    InsereazaCercul(i); // adaugarea discurilor
  for (i=ultimulDisc+1;i<n;i++)
    dispensabil[i] = 1; // marcarea discurilor dispensabile de la sfarsit
  // numararea discurilor dispensabile
  k = 0;
  for (i=0;i<n;i++)
    if (dispensabil[i])
      k++;
}

void ScrieSolutia(void){
  FILE *f=fopen("DISCURI.OUT","wt");
  fprintf(f,"%d\n",k);
  for (int i=0;i<n;i++)
    if (dispensabil[i])
      fprintf(f,"%d\n",i+1);
  fclose(f);
}

void main(void){
  CitesteDate();
  DeterminaSolutia();
  ScrieSolutia();
}