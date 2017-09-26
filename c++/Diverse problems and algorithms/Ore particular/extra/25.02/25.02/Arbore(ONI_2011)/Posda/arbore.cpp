#include<stdio.h>
#include<vector>
using namespace std;

#define ll long long
#define MOD 666013 
#define NMAX 100005
#define pb push_back

vector<int> v[NMAX];
int n;
ll fact[NMAX];
ll sol[NMAX];
int tata[NMAX];
ll el[NMAX];
char viz[NMAX];

ll rid_log(ll val,ll put)
{
	if(put==1)
		return val;
	ll val2=rid_log(val,put/2);
	val2*=val2;
	if(val2>=MOD)
		val2%=MOD;
	if(!(put&1))
		return val2;
	val2*=val;
	if(val2>=MOD)
		val2%=MOD;
	return val2;
}

void dfs(int nod)
{
	int vec,nr,i,lim=v[nod].size();
	viz[nod]=1;
	for(i=0;i<lim;i++)
	{
		vec=v[nod][i];
		if(!viz[vec])
			dfs(vec);
		else
			tata[nod]=vec;
	}	
	for(i=0;i<lim;i++)
		if(v[nod][i]!=tata[nod])
			el[nod]+=el[v[nod][i]];
	
	sol[nod]=1;	nr=0;
	for(i=0;i<lim;i++)	
	{
		vec=v[nod][i];
		if(vec==tata[nod])
			continue;
		sol[nod]*=sol[vec];
		if(sol[nod]>=MOD)
			sol[nod]%=MOD;
		ll invm=rid_log(fact[el[vec]],MOD-2);
		sol[nod]*=invm;
		if(sol[nod]>=MOD)
			sol[nod]%=MOD;
	}		
	sol[nod]*=fact[el[nod]];
	if(sol[nod]>=MOD)
		sol[nod]%=MOD;
	el[nod]++;
}

int main ()
{
	int i,a,b;
	freopen("arbore.in","r",stdin);
	freopen("arbore.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}	
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=(fact[i-1]*i)%MOD;
	dfs(1);
	int val=sol[1];
	printf("%d\n",val);
	return 0;
}






