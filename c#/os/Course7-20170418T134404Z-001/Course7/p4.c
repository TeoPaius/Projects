#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int n = 0;

void* f(void* p)
{
    int k = 0;
    int* r = (int*)p;
    while (n < 30)
    {
        n++;
        k++;
        sleep(1);
    }
    printf("%d cycled %d times\n", *r, k);
    return NULL;
}

int main()
{
    pthread_t t[10];

    for (int i = 0; i < 10; i++)
        pthread_create(&t[i], NULL, f, &i);

    for (int i = 0; i < 10; i++)
        pthread_join(t[i], NULL);

    return 0;
}
