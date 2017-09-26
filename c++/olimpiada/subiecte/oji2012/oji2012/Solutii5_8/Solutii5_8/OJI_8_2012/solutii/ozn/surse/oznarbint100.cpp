//Marius Nicoli
#include <stdio.h>
#define DIM 1000009
#define DN (nod<<1)
int N, K, k, a, b, c, i, val, aux;
int V[DIM], A[DIM];

void update(int st, int dr, int nod, int a, int b, int val) {
	int mij;
	if (a<=st && dr<=b) {
		A[nod] += val;
	} else {
		mij = (st+dr)/2;
		if (a<=mij) {
			A[DN] += A[nod];
			A[DN+1] += A[nod];
			A[nod] = 0;
			update(st, mij, DN, a, b, val);
		}
		if (b>mij) {
			A[DN] += A[nod];
			A[DN+1] += A[nod];
			A[nod] = 0;
			update(mij+1, dr, DN+1, a, b, val);
		}
		V[nod] = V[DN] + V[DN+1];
	}
}


int query(int st, int dr, int nod, int a, int b) {
	int sum,x,mij;
	if ((a<=st) && (dr<=b)){
		V[nod] += A[nod]*(dr-st+1);
		A[nod] = 0;
		return V[nod];
	} else {
		mij = (st+dr)/2;
		sum = 0;

		if (a<=mij) {

			A[DN] += A[nod];
			A[DN+1] += A[nod];
			A[nod] = 0;
			x = query(st, mij, DN, a, b);
			
			sum += x;
		}
		if (b>mij) {
			A[DN] += A[nod];
			A[DN+1] += A[nod];
			A[nod] = 0;
			x = query(mij+1,dr, DN+1, a, b);
			sum += x;
		}
		V[nod] = V[DN] + A[DN]*(mij-st+1) + V[DN+1] + A[DN+1]*(dr-mij);
		return sum;
	}
}
int main() {

	FILE *f = fopen("ozn.in","r");
	FILE *g = fopen("ozn.out","w");
	fscanf(f,"%d %d",&N,&K);
	for (i=1;i<=N;i++) {
		fscanf(f,"%d %d %d %d %d",&a, &c, &b, &c, &val);
		update(1, 500003, 1, a, b, val);
	}
	for (i=1;i<=K;i++) {
		fscanf(f,"%d",&k);
		fprintf(g,"%d\n",aux = query(1, 500003, 1, k, k));
	}
	fclose(g);
	fclose(f);
	return 0;
}
