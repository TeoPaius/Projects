#include <fstream.h>
#define IN  "gems.in"
#define OUT "gems.out"

const int MAX = 10001;

typedef struct nod {
	int vf;
	nod* urm;
} NOD, *PNOD;

PNOD   L[MAX];
int  costmin, n;
int s[MAX];        // selectat
int smin[MAX][4];  // smin[i][0] - suma minima din subarborele cu rad in i, daca valoarea din nod este 1
				   // smin[i][1] -  -II- i, daca valoarea din nod este 2
	               // smin[i][2] -  -II- i, daca valoarea din nod este 3
void Read();
void Add(int, int);
void DF(int);
void Write();

int main()
{
	Read();
	DF(1);
	Write();

	return 0;
}

void Read ()
{
	ifstream fin(IN);
	int i, v1, v2;

	fin >> n;
	for ( i = 1; i < n; i++ )
	{
    	fin >> v1 >> v2;
    	Add(v1, v2);
    	Add(v2, v1);
		smin[i][1] = 1;           // se atribuie cele mai mici valori 1, 2, 3
        smin[i][2] = 2;
        smin[i][3] = 3;
	}
    smin[n][1] = 1;
	smin[n][2] = 2;
	smin[n][3] = 3;
	fin.close();
}

int Min (int a, int b)
{
	return a <= b ? a : b;
}

void DF(int nod)
{
    s[nod] = 1;
	for (PNOD p = L[nod]; p; p = p->urm )
	{
		if ( s[p->vf] ) continue;  // tata
		DF(p->vf);
    	smin[nod][1] += Min(smin[p->vf][2], smin[p->vf][3]);
      	smin[nod][2] += Min(smin[p->vf][1], smin[p->vf][3]);
      	smin[nod][3] += Min(smin[p->vf][1], smin[p->vf][2]);
  	}
}

void  Write()
{
	ofstream fout(OUT);
	costmin = Min(smin[1][1], Min(smin[1][2], smin[1][3]));
	fout << costmin;
  	fout.close();
}

void Add(int v1, int v2)
{
    PNOD p = new NOD;
    p->vf = v2;
    p->urm = L[v1];
    L[v1] = p;
}    

