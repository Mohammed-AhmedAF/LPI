#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

void signal_handle(int signal)
{
    printf("You can't stop\r\n");
}

int main(int argc, char * argv[])
{
    struct sigaction sa;
    sa.sa_handler = signal_handle;
    sigaction(SIGTSTP,&sa,NULL);

    int number;
    printf("Please enter a number: \r\n");
    scanf("%d",&number);
    printf("Rusult of multiplication is %d\r\n",number*5);
    return 0;
}