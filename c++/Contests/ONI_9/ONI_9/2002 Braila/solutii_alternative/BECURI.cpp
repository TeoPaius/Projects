
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 2
// Problema: Becuri

#include <stdio.h>
#include <string.h>

#define DIM 100
#define MAX 15000

FILE *f=NULL;
int m=0,n=0,i=0,j=0,x=0,min=MAX;
signed char a[DIM][DIM]={0},ln[DIM+1]={0},cl[DIM+1]={0};
signed char la[DIM][DIM]={0},lln[DIM+1]={0},lcl[DIM+1]={0};
int lmin=0;
void line(int);
void col(int);
inline void applyline(int);
inline void applycol(int);
inline int idline(int);
inline int idcol(int);
int main(int argc, char *argv[])
{
 f=fopen("BECURI.IN","rt");
 fscanf(f,"%d %d",&m,&n);
 for(i=0;i<m;i++)
  for(j=0;j<n;fscanf(f,"%d",&x),a[i][j++]=x);
 fclose(f);
 for(i=0;i<m;x=0,line(i),x=1,line(i++));
 for(i=0;i<n;x=0,col(i),x=1,col(i++));
 f=fopen("BECURI.OUT","wt");
 if(min<MAX)
 {
  if(cl[0])
    for(i=1;i<=cl[0];i++) fprintf(f,"%d ",cl[i]+1);
  else fprintf(f,"0");
  fprintf(f,"\n");
  if(ln[0])
    for(i=1;i<=ln[0];i++) fprintf(f,"%d ",ln[i]+1);
  else fprintf(f,"0");
 }
 else fprintf(f,"-1");
 fclose(f);
 return 0;
}
void line(int l)
{
  int i=0;
  memset(la,0,sizeof(la));
  memset(lln,0,sizeof(lln));
  memset(lcl,0,sizeof(lcl));
  lmin=0;
  if(x) { applyline(l); lln[++lln[0]]=l; }
  for(i=0;i<n;i++)
    if(a[l][i]!=la[l][i]) { applycol(i); lcl[++lcl[0]]=i,++lmin; }
  for(i=0;i<l;i++)
    if(!idline(i))
    {
      applyline(i); lln[++lln[0]]=i,++lmin;
      if(!idline(i)) return;
    }
  for(i=l+1;i<m;i++)
    if(!idline(i))
    {
      applyline(i); lln[++lln[0]]=i,++lmin;
      if(!idline(i)) return;
    }
  if(lmin<min)
  {
    min=lmin;
    memcpy(ln,lln,sizeof(signed char)*(lln[0]+1));
    memcpy(cl,lcl,sizeof(signed char)*(lcl[0]+1));
  }
}
void col(int c)
{
  int i=0;
  memset(la,0,sizeof(la));
  memset(lln,0,sizeof(lln));
  memset(lcl,0,sizeof(lcl));
  lmin=0;
  if(x) { applycol(c), lcl[++lcl[0]]=c; }
  for(i=0;i<m;i++)
    if(a[i][c]!=la[i][c]) { applyline(i); lln[++lln[0]]=i,++lmin; }
  for(i=0;i<c;i++)
    if(!idcol(i))
    {
      applycol(i); lcl[++lcl[0]]=i,++lmin;
      if(!idcol(i)) return;
    }
  for(i=c+1;i<n;i++)
    if(!idcol(i))
    {
      applycol(i); lcl[++lcl[0]]=i,++lmin;
      if(!idcol(i)) return;
    }
  if(lmin<min)
  {
    min=lmin;
    memcpy(ln,lln,sizeof(signed char)*(lln[0]+1));
    memcpy(cl,lcl,sizeof(signed char)*(lcl[0]+1));
  }
}
inline void applyline(int l)
{
  for(int i=0;i<n;i++) la[l][i]=!la[l][i];
}
inline void applycol(int c)
{
  for(int i=0;i<m;i++) la[i][c]=!la[i][c];
}
inline int idline(int l)
{
  for(int i=0;i<n;i++) if(la[l][i]!=a[l][i]) return 0;
  return 1;
}
inline int idcol(int c)
{
  for(int i=0;i<m;i++) if(la[i][c]!=a[i][c]) return 0;
  return 1;
}
