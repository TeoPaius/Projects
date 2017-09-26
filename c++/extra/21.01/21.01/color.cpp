#define White 0
#define Gray 1
#define Black 2
int color[1000];

void Df(int x)
{
	color[x] = Gray;
	for ( const int& f : G[x])
		if ( color[f] == White )
			Df(f);
	
	for (const int& f : G[x])
		if ( color[f] == Black )
			// proceseaza fiu
	
	color[x] = Black;
}



