#include<stdio.h>
#define T 5
long n,b,d[10][3],nr;
FILE *fin=fopen("fact.in","r");
FILE *fout=fopen("fact.out","w");
void desc(long b){
     nr=0;
     for(long i=2;b>1;i++)
             if(!(b%i)){
                        d[nr][0]=i;
                        d[nr][1]=0;
                        while(!(b%i)){
                                      d[nr][1]++;
                                      b/=i;
                        }
                        nr++;
             }
}
long cifra(){
    long i,j,p=1,aux;
    for(j=0;j<nr;j++)
                     d[j][2]=0;
    for(i=1;i<=n;i++){
                      aux=i;
                      for(j=0;j<nr;j++){
                                       while(!(aux%d[j][0])){
                                                             d[j][2]++;
                                                             aux/=d[j][0];
                                       }
                      }
                      p=(p*(aux%b))%b;
    }
    return p;
}
long minim(){
    long min=d[0][2]/d[0][1];
    for(long i=1;i<nr;i++)
            if(d[i][2]/d[i][1]<min)
                                   min=d[i][2]/d[i][1];
    return min;
}
long calcul(){
    long i,j,p=cifra();
    long min=minim();
    for(i=0;i<nr;i++)
                     for(j=0;j<d[i][2]-d[i][1]*min;j++)
                                                       p=(p*d[i][0])%b;
    return p;
}
void scrie(){
     long x=calcul();
     if(x<10)
              fprintf(fout,"%ld\n",x);
     else
         fprintf(fout,"%c\n",'A'+(x-10));
}
int main(){
    for(int i=0;i<T;i++){
            fscanf(fin,"%ld%ld",&n,&b);
            desc(b);
            scrie();
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
