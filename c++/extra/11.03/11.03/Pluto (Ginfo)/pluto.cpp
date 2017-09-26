#include <fstream.h>
#include <math.h>
#define INFILE "pluto.in"
#define OUTFILE "pluto.out"
#define INFINITY 10001
#define MAX 101

typedef struct node {
	int info;
	node * next;
} NODE, * PNODE;

PNODE head, tail;

int f[MAX][MAX], r[MAX], c[MAX][MAX], seen[MAX], t[MAX], n, m, flowvalue;

void ReadData();
void Add(int vertex);
void Remove();
void Solve();
void BreadthFirstSearch();
void Print();

int main()
{
	ReadData();
	Solve();
	Print();

	return 0;
}

void ReadData()
{
	ifstream fin(INFILE);

	int i = 0, j = 0, capacity = 0;

	fin >> n >> m;

	for ( i = 1; i <= n; i++ )
	{
		 fin >> capacity;
		 c[n+i][2*n+1] = capacity;
		 for ( j = n + 1; j <= 2 * n; j++ )
			if ( j != n + i ) c[i][j] = 1; // evita i --> iprim
	}

	for ( i = 1; i <= n; i++ )
	{
		fin >> capacity;
		c[0][i] = capacity;
	}

	n *= 2;

	fin.close();
}

void Add(int vertex)
{
	if ( !head )
	{
		head = new NODE;
		head->info = vertex;
		head->next = NULL;
		tail = head;
	}
	else
	{
		PNODE p = new NODE;
		p->info = vertex;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
}

void Remove()
{
	PNODE p = head;
	head = head->next;
	delete p;
}

void Solve()
{
	int i = 0, j = 0;

	do
	{
		memset(seen, 0, sizeof(seen));
		head = tail = NULL;
		Add(0);
		seen[0] = 1;
		r[0] = INFINITY;
		BreadthFirstSearch();
		if ( seen[n+1] )
		{
			flowvalue += r[n+1];
			i = n + 1;
			while ( i != 0 )
			{
				j = abs(t[i]);
				if ( t[i] >= 0 ) f[j][i]++;
					else f[i][j]--;
				i = j;
			}
		}
		if ( flowvalue == m ) break;
	} while ( seen[n+1] );
}

void BreadthFirstSearch()
{
	PNODE x = NULL;
	int i = 0, j = 0;

	x = head;  // nodul 0

	while ( x )
	{
			j = x->info;
			for ( i = 1; i <= n + 1; i++ )
				if ( !seen[i] )
				{
						if ( c[j][i] - f[j][i] > 0 )
						{
							if ( c[j][i] - f[j][i] < r[j] ) r[i] = c[j][i] - f[j][i];
								else r[i] = r[j];
							Add(i);
							seen[i] = 1;
							t[i] = j;
						}
						if ( f[i][j] )
						{
							if ( f[i][j] < r[j] ) r[i] = f[i][j];
								else r[i] = r[j];
							Add(i);
							seen[i] = 1;
							t[i] = -j;
						}
				}
		x = x->next;
		Remove();
	}
}

void Print()
{
	ofstream fout(OUTFILE);

	int i = 0, j = 0;

	if ( flowvalue == m )
	{
		fout << "YES" << endl;
		for ( i = 1; i <= n / 2; i++ )
			for ( j = n / 2 + 1; j <= n; j++ )
				if ( f[i][j] )
					fout << j - n / 2 << " " << i << endl;
	}
	else fout << "NO" << endl;

	fout.close();
}
