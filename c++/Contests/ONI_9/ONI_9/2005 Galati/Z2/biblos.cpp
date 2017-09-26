//O(n)
#include<fstream.h>
#include<string.h>

#define MAX 30010
#define FIn  "biblos.in"
#define FOut "biblos.out"

#ifndef __BORLANDC__
	#define huge
#endif

int huge carti[MAX];
long huge c_max[MAX];
int n;

void Read()
{
	ifstream in(FIn);
	in >> n;
	int i, x;
	for(i = 1; i <= n; i++)
		in >> x,
		carti[i] = x;
	in.close();
}

void Solve_and_Write()
{
	int i, j;
	long max;

	max = c_max[1] = carti[1];
	c_max[0] = c_max[2] = -10000;

	for(i = 3; i <= n; i ++)
	{
		if (c_max[i - 2] > c_max[i - 3])
			c_max[i] = carti[i] + c_max[i-2];
		else
			c_max[i] = carti[i] + c_max[i-3];
		if (c_max[i] > max)
				max = c_max[i];
	}

	/* afisarea */
	ofstream out(FOut);
	out << max << endl;
	out.close();

}

int main()
{
	Read();
	Solve_and_Write();
	return 0;
}
