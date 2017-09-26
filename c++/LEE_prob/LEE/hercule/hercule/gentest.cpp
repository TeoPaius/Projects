#include <fstream.h>
#include <stdlib.h>

ofstream fout("10.in");
int m = 100;
int n = 100;
int N = 150;
int ip = 1;
int jp = 100;
int is = 100;
int js = 1;


int main()
{
	fout << m << " " << n << "\n";
	randomize();
	for ( int i = 1; i <= m; i++ )
		for (int j = 1; j <= n; j++ )
			fout << random(N) << "\n";
	fout << ip << " " << jp << " " << is << " " << js;
	fout.close();

	return 0;
}
