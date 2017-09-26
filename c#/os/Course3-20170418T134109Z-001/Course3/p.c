#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (fork())
		{
			for (int j = 0; j < 10; j++)
			{
				printf("I am %d son of a %d.\n", getpid(), getppid());
				sleep(1);
			}
			exit(0);
		}
	}
	
	for (i = 0; i < 3; i++)
	{
		wait(0);
	}
}
