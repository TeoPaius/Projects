#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/usr/bin/sort", "/usr/bin/sort", "-r", "p1.c", NULL);
}
