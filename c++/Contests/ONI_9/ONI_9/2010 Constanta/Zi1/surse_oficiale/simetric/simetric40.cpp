#include<stdio.h>
#include<string.h>

#define maxn 128 * 4

short int N, V[ maxn ][ maxn ], Max[ maxn][ maxn ], M;
int nr[ maxn];

int main()
{
	freopen("simetric.in","r",stdin);
	freopen("simetric.out","w",stdout);
	
	
	memset( nr, 0, sizeof( nr ));
	memset( Max, 0, sizeof( Max ));
	
	scanf("%d %d",&N, &M);
	
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= M; ++j)
			scanf("%d", &V[ i ][ j ]); 
	int optim = 0;
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= M; ++j)
		{
			int ok = 1;
			for( int l = 1; i + l - 1 <= N && l + j - 1 <= M; l++)
			{
				for( int k = 1; k <= l; ++k)
					if( V[ i + l - 1 ][ j + k - 1 ] != V[ i + k - 1 ][ j + l - 1 ]  ) 
						{ ok = 0; break;}
				if( ok == 0) break;
				
				nr[ l ]++;
				if( l > optim )
					optim = l;
			}
		}
	
	for( int i = 1; i <= optim; i++)
		printf("%d\n", nr[i]); 
		

	

		
	return 0;
}
