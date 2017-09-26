//Solutia oficiala - implementare STL
//100 puncte
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#define N 100010
using namespace std;
int n,k,K,i,j,v,big,ST,DR,MI,BST[N];
int oo=(1<<30)+100;
vector< pair<int,int> > UPD[N];
char B[N];
int main()
{
    freopen("blis.in","r",stdin);
    freopen("blis.out","w",stdout);
    scanf("%d%s",&k,B+1);n=strlen(B+1);
    for(i=1;i<=n+1;i++)BST[i]=oo;BST[0]=-1;
    for(i=1;i<=n;i++)
    {
        v=0;K=min(n,i+k-1);
        for(j=i;j<=K;j++)
        {
            v=(v<<1)|(B[j]-'0');big=max(big,v);
            for(ST=0,DR=i+1;DR-ST-1;)
            {
                MI=(ST+DR)/2;
                if(BST[MI]<v)ST=MI;
                else DR=MI;
            }
            if(BST[DR]>v)UPD[j].push_back(make_pair(DR,v));
        }
        for(vector< pair<int,int> >::iterator it=UPD[i].begin();it!=UPD[i].end();it++)
            if(BST[it->first]>it->second)
                BST[it->first]=it->second;
    }
    printf("%d\n",big);
    for(ST=0,DR=n+1;DR-ST-1;)
    {
        MI=(ST+DR)/2;
        if(BST[MI]<oo)ST=MI;
        else DR=MI;
    }
    printf("%d\n",ST);
    return 0;
}
