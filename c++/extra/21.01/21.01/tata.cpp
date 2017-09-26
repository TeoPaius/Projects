

int t[1000];

void Df(int x)
{
	for (int & f : G[x])
	{
		if ( f == t[x] ) continue;
		t[f] = x;
		Df(f);
	}
}

void Df(int x, int t)
{
	for (const int& f : G[x] )
	{
		if ( f == t ) continue;
		Df(f, x);
}




