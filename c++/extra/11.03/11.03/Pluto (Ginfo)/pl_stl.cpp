#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void Read();
void Build();
int BF();
void Flux();
void Augment();
void Write();

typedef vector<int> VI;
typedef vector<int>::iterator IT;

int n, m;
int S, T;
int flow;
vector<VI > C;
VI Min, t, In, Out;
vector<bool> s;
queue<int> Q;

int main()
{
    Read();
    Build();
    Flux();
    Write();
    return 0;
}

void Read()
{
    FILE *fin = fopen("pluto02.in", "r");
    fscanf(fin, "%d%d", &n, &m);
    
    C.resize(2*n+2);
    Min.resize(2*n+2);
    s.resize(2*n+2);
    t.resize(2*n+2);
    In.resize(2*n+2);
    Out.resize(2*n+2);
    for (int i = 0; i <= 2*n+2; i++)
        C[i].resize(2*n+2);
        
    for (int i = 1; i <= n; i++)
        fscanf(fin, "%d", &Out[i]);
    for (int i = 1; i <= n; i++)
        fscanf(fin, "%d", &In[i]);
    
    fclose(fin);
}

void Flux()
{
    while (BF()) Augment();
}

int BF()
{
    s.assign(2*n+2, 0);
    t.assign(2*n+2, 0);
    Min.assign(2*n+2, 0);
    
    Q.push(0);
    s[0] = true;
    int i, j;
    
    while (!Q.empty())
    {
        i = Q.front();
        for (j = 0; j <= T; j++)
            if (C[i][j] && !s[j])
            {
                Q.push(j);
                s[j] = true;
                t[j] = i;
                Min[j] = 1;
                if (j == T) return 1;
            }
        Q.pop();
    }
    return 0;
}

void Build()
{
    S = 0, T = 2*n + 1;
    for (int i = 1; i <= n; i++)
    {
        C[S][i] = Out[i];
        C[n+i][T] = In[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][n+j] = (i != j);
}

void Augment()
{
    for (int i = T; i != S; i = t[i])
    {
        C[t[i]][i]--;
        C[i][t[i]]++;
    }
    flow++;
}

void Write()
{
    FILE *fout = fopen("pluto.out", "w");
    
    if (flow != m)
        fprintf(fout, "NO\n");
    else
    {
        fprintf(fout, "YES\n");
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (C[n+j][i]) fprintf(fout, "%d %d", i, j);
    }
    
    fclose(fout);
}

