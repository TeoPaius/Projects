
// Olimpiada Judeteana de Informatica, 9 martie 2002
// Clasele XI-XII
// Problema 1 (Urgenta)

#pragma option -a -r -G -O2 -Ox -mh
#include <stdio.h>
#define DIM 32385
typedef struct tagMUCHIE{
  unsigned char i,j,p;
}muchie;
int i,j,l,m,C,o[DIM],huge o2[DIM],p[256];
unsigned char n,k,huge s[DIM],huge bk[DIM];
muchie huge a[DIM];
unsigned long gravmax=0;
FILE *f;
void init();
void ord();
unsigned char getset(unsigned char);
void reun(unsigned char,unsigned char);
void solve();
void write();
void main()
{
  init();
  solve();
  write();
}
void init()
{
  f=fopen("URGENTA.IN","rt");
  for(fscanf(f,"%d %d %d",&n,&m,&k),i=0;i<m;*(s+i)=1,*(o+i)=i,fscanf(f,"%d %d %d",&((a+i)->i),&((a+i)->j),&((a+i)->p)),gravmax+=((a+(i++))->p));
  fclose(f);
}
void ord() // Ordonare BucketSort (dupa cifre) in vectorul o (o2 e vector auxiliar) a muchiilor crescator dupa costuri
{
  for(i=0;i<m;*(bk+i)=((a+(*(o+i)))->p)%10,i++);
  for(i=0,l=0;i<10;i++)
    for(j=0;j<m;j++)
      if(*(bk+j)==i) *(o2+(l++))=*(o+j);
  for(i=0;i<m;*(o+i)=*(o2+i),i++);

  for(i=0;i<m;*(bk+i)=(((a+(*(o+i)))->p)/10)%10,i++);
  for(i=0,l=0;i<10;i++)
    for(j=0;j<m;j++)
      if(*(bk+j)==i) *(o2+(l++))=*(o+j);
  for(i=0;i<m;*(o+i)=*(o2+i),i++);

  for(i=0;i<m;*(bk+i)=((a+(*(o+i)))->p)/100,i++);
  for(i=0,l=0;i<10;i++)
    for(j=0;j<m;j++)
      if(*(bk+j)==i) *(o2+(l++))=*(o+j);
  for(i=0;i<m;*(o+i)=*(o2+i),i++);
}
unsigned char getset(unsigned char x)  // in ce comp. conexa se afla vf. x
{
  if(*(p+x)>=0) *(p+x)=getset(*(p+x));  // daca parintele p[x] a lui x e negativ => x este comp. conexa, altfel
  return (*(p+x)>=0)? *(p+x):x;          // returneaza parintele parintelui lui x
}
void reun(unsigned char x,unsigned char y) // uneste 2 comp. conexe (multimi disjuncte de vf.)
{
  if(x!=y)
    if(*(p+x)>*(p+y)) *(p+x)=y;
    else
    {
      *(p+y)=x;
      if(*(p+x)==*(p+y)) --(*(p+x));
    }
}
void solve()
{
  ord();
  for(i=0;i<n;*(p+(i++))=-1);
  for(i=0,C=m,j=n;i<m && j>k;i++)  // uneste muchiile de cele mai mici costuri pana raman k comp. conexe
  {
    unsigned char x=getset((a+(*(o+i)))->i),y=getset((a+(*(o+i)))->j);
    if(x!=y)
    {
      reun(x,y);
      *(s+(*(o+i)))=0,--C,--j;
      gravmax-=(a+(*(o+i)))->p;
    }
  }
}
void write()
{
  f=fopen("URGENTA.OUT","wt");
  fprintf(f,"%lu\n%d\n",gravmax,C);
  for(i=0;i<m;i++)
    if(*(s+i)) fprintf(f,"%d %d\n",(a+i)->i,(a+i)->j);
  fclose(f);
}
