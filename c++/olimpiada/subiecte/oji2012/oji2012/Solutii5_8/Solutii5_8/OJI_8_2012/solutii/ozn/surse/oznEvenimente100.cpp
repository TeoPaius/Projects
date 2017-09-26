//Marius Nicoli
#include <stdio.h>
#define DIM 20010
#include <algorithm>

using namespace std;

struct inregistrare {
	int t;
	int x;
	int v;
	int p;
};

inregistrare V[DIM*3], inr;

int cmp (inregistrare a, inregistrare b) {
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.t < b.t;
}

int cmp1 (inregistrare a, inregistrare b) {
	return a.p < b.p;
}

int N, K, M, i, sum, a, b, c, d, e, k;

int main() {
	FILE *f = fopen("ozn.in","r");
	FILE *g = fopen("ozn.out","w");
	
	fscanf(f,"%d %d",&N, &K);
	
	for (i=1;i<=N;i++) {
		fscanf(f,"%d %d %d %d %d",&a, &b, &c, &d, &e);
		inr.t = 1;inr.x = a;inr.v = e;inr.p = K+1;
		V[++M] = inr;
		inr.t = 3;inr.x = c;inr.v = e;inr.p = K+1;
		V[++M] = inr;
	}
	
	for (i=1;i<=K;i++) {
		fscanf(f,"%d",&k);
		inr.t = 2;
		inr.x = k;
		inr.p = i;
		V[++M] = inr;
	}
	
	sort(V+1, V+M+1, cmp);
	
	for (i=1;i<=M;i++) {
		if (V[i].t == 1)
			sum += V[i].v;
		else
			if (V[i].t == 3)
				sum -= V[i].v;
			else
				V[i].v = sum;
	}
	
	sort(V+1, V+M+1, cmp1);
	
	for (i=1;i<=K;i++)
		fprintf(g,"%d\n",V[i].v);
	
	fclose(g);
	fclose(f);
	return 0;
}