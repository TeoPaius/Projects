//Marius Nicoli
#include <stdio.h>
#define DIM 20010
#include <algorithm>

using namespace std;
struct inter {
	int st;
	int dr;
	int nr;
};

inter V[DIM];

int K, N, i, j, c, sum, k;

int cmp(inter a, inter b) {
	if (a.dr != b.dr)
		return a.dr < b.dr;
	else
		return a.st < b.st;
}

int p, u, m;


int main() {
	FILE *f = fopen("ozn.in","r");
	FILE *g = fopen("ozn.out","w");
	fscanf(f,"%d %d",&N,&K);
	for (i=1;i<=N;i++) {
		fscanf(f,"%d %d %d %d %d",&V[i].st, &c, &V[i].dr, &c, &V[i].nr);
	}
	sort(V+1, V+N+1, cmp);
	
	for (i=1;i<=K;i++) {
		fscanf(f,"%d",&k);
		sum = 0;
		for (j=N;V[j].dr >=k;j--)
			if (V[j].st <= k)
				sum += V[j].nr;
		fprintf(g,"%d\n",sum);
	}
	
	return 0;
}