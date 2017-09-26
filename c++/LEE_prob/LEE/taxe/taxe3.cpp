#include <fstream.h>

const int di[] = { 1, 0, -1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int b[102][102], a[102][102], n, s, i, j, ii, jj, p, modif;

void Citeste();
void Scrie();
void Lee();
int Bun(int, int);

int main()
{
	Citeste();
	Lee();
	Scrie();

	return 0;
}

void Citeste()
{
    ifstream f("taxe.in");
	 f >> s >> n;
    for(i = 1; i <= n; i++)
          for(j = 1; j <= n; j++)
			 {
					f >> b[i][j];
					a[i][j] = 32000;
			 }
    f.close();
}

void Scrie()
{
	 ofstream g("taxe.out");
	 if(s < a[n][n]) g << -1;
	 else g << s - a[n][n];
}

int Bun(int k, int l)
{
    if (k < 1 || l < 1 || k > n || l > n) return 0;
	return 1;
}

void Lee()
{
    a[1][1] = b[1][1];
    modif = 1;
    do
    {
       modif = 0;
       for(i = 1; i <= n; i++)
       		for(j = 1; j <= n; j++)
                for(p = 0; p < 4; p++)
                {
					ii = i + di[p];
					jj = j + dj[p];
					if(Bun(ii, jj))
						if (a[ii][jj] > (a[i][j] + b[ii][jj]))
						{
							a[ii][jj] = a[i][j] + b[ii][jj];
							modif = 1;
						}
                }
    } while( modif);
}
