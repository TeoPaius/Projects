//sursa oficiala - liste implementate cu pointeri
//100 puncte
#include<cstdio>
#include<cstring>
using namespace std;
struct nod{int val,lg; nod *urm;};
nod *P[100010],*paux;
int k,n,i,v,j,K,ST,DR,MI,LMAX,sol,BST[100010],oo=2000000000;
char B[100010];
int main()
{
    freopen("blis.in","r",stdin);
    freopen("blis.out","w",stdout);
    scanf("%d",&k);
    scanf("%s",B+1);
    n=strlen(B+1);
    for(i=1;i<=n+1;i++)BST[i]=oo;BST[0]=-oo;LMAX=0;
    for(i=1;i<=n;i++)
    {
        v=0;K=i+k-1<n?i+k-1:n;
        for(j=i;j<=K;j++)
        {
            v<<=1;v|=B[j]-'0';sol=v>sol?v:sol;
            for(ST=0,DR=LMAX+1;DR-ST-1;)
            {
                MI=(ST+DR)>>1;
                if(BST[MI]<v)ST=MI;
                else DR=MI;
            }
            if(v<BST[DR])
            {
                paux=new nod;paux->val=v;paux->lg=DR;paux->urm=P[j];P[j]=paux;
            }
        }
        for(;P[i];)
        {
            paux=P[i];P[i]=P[i]->urm;
            if(BST[paux->lg]>paux->val)BST[paux->lg]=paux->val;
            delete paux;
        }
        while(BST[LMAX+1]<oo)LMAX++;
    }
    printf("%d\n%d",sol,LMAX);
    return 0;
}
