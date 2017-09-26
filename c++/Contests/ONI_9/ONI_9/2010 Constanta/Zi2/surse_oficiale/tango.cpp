#include<stdio.h>

#define prim 999983

int nr[20];

int main()
{
	int n=0, k=0;
	long long sol = 0;
	freopen("tango.in","r",stdin);
	freopen("tango.out","w",stdout);	
	scanf("%d %d", &n, &k);
	//printf("%d %d\n",n,k);
	//return 0;
	
	for( int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		nr[ x ]++;
	}

	nr[ 0 ] = 1;
	for( int i1 = 1; i1 <= 8; i1++)
	{
		if( nr[ i1 ] == 0) continue;
		for( int i2 = 0; i1 + i2 <= 8; i2++)
		{
			if( i1 + i2 != 8 && i2 == 0) continue;
			if( nr[ i2 ] == 0) continue;
			for( int i3 = 0; i1 + i2 + i3 <= 8; i3++)
			{
				if( nr[ i3 ] == 0) continue;
				if( i1 + i2 + i3 != 8 && i3 == 0) continue;
				for( int i4 = 0; i1 + i2 + i3 + i4 <= 8; i4++)
				{
					if( nr[ i4 ] == 0) continue;
					if( i1 + i2 + i3 + i4 != 8 && i4 == 0) continue;
					for( int i5 = 0; i1 + i2 + i3 + i4 +i5 <= 8; i5++)
					{
						if( nr[ i5 ] == 0) continue;
						if( i1 + i2 + i3 + i4 +i5 != 8 && i5 == 0) continue;
						for( int i6 = 0; i1 + i2 + i3 + i4 +i5 + i6 <= 8; i6++)
						{
							if( nr[ i6 ] == 0) continue;
							if( i1 + i2 + i3 + i4 + i5 + i6 != 8 && i6 == 0) continue;
							for( int i7 = 0; i1 + i2 + i3 + i4 +i5 + i6 + i7 <= 8; i7++)
							{
								if( nr[ i7 ] == 0) continue;
								if( i1 + i2 + i3 + i4 + i5 + i6 + i7 != 8 && i7 == 0) continue;
								for( int i8 = 0; i1 + i2 + i3 + i4 +i5 + i6 + i7 + i8 <= 8; i8++)
								{
									if( i1 + i2 + i3 + i4 +i5 + i6 + i7 + i8 == 8 )
									{
										long long temp = ((long long )nr[ i1 ] * nr[ i2 ] * nr[ i3 ] ) % prim;
										temp *= ((long long )nr[ i4 ] * nr[ i5 ] * nr[ i6 ] ) % prim; temp %= prim;
										temp = (long long)temp * nr[ i7 ] * nr[ i8 ] % prim;
										sol = ( sol + temp) % prim;
										
									}
									if( nr[ i8 ] == 0) continue;
								}
							}
						}
					}
				}
			}
		}
	}
	
	int p = k / 8;
	long long rez = 1;
	long long put = sol;
	while( p )
	{
		if ( p & 1 ) rez = (put * rez) % prim;
		put = ( put * put ) % prim;
		p >>= 1;
	}
	
	printf("%d\n",(int) rez);
	fcloseall();
	return 0;

}
