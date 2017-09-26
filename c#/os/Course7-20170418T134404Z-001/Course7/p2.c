#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("111111\n");
    if (fork() == 0)
    {
        execl("/usr/bin/sort", "/usr/bin/sort", "-r", "p1.c", NULL);
        exit(0);
    }
    wait(0);
    printf("222222\n");

    return 0;
}
