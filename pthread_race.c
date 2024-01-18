#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mail = 0;

pthread_mutex_t mut;

void * routine()
{
    for (int i = 0; i < 10000;i++)
    {
        pthread_mutex_lock(&mut);
        mail++;
        pthread_mutex_unlock(&mut);
    }
}

int main(void)
{
    pthread_t p1,p2;
    pthread_mutex_init(&mut,NULL);

    if (pthread_create(&p1,NULL,&routine,NULL) != 0)
    {
        return -1;
    }
    if (pthread_create(&p2,NULL,routine,NULL) != 0)
    {
        return -1;
    }
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("The mail has %d\r\n",mail);

    return 0;

}