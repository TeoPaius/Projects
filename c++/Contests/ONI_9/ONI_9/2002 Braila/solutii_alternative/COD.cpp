
// Olimpiada Nationala de Informatica
// Braila, aprilie 2002
// Clasa a IX-a

// Ziua 2
// Problema: Cod

#include <stdio.h>

#define DIM 10

char s[DIM+1]={0},i=0,j=0,l=0;
unsigned long n=0,p=1;
FILE *f=NULL;
int main(int argc, char *argv[])
{
 f=fopen("COD.IN","rt"); fscanf(f,"%s",s); fclose(f);
 while(s[l]) ++l;
 if(l==1) n=s[0]-'a'+1;
 else if(l>1)
 {
  for(i=1;i<l;i++)
    if(s[i]<=s[i-1]) break;
  if(i>=l)
  {
    for(i=1;i<l;n+=p,i++)  // Combinari de 26 luate cate i(1<i<lungimea cuv.)
          for(j=26-i+1,p=1;j<27;p=(p*j)/(j+i-26),j++);

    for(i=1;i<=s[0]-'a';n+=p,i++)
      for(j=l,p=1;j<=26-i;p=(p*j)/(j-l+1),j++);
    for(char k=1;k<l;k++)
      for(i=s[k-1]-'a'+2;i<=s[k]-'a';n+=p,i++)
        for(j=l-k,p=1;j<=26-i;p=(p*j)/(j-l+k+1),j++);
    ++n;
  }
 }
 f=fopen("COD.OUT","wt"); fprintf(f,"%lu",n); fclose(f);
 return 0;
}
