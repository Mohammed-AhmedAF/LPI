#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
    int pid2;
    int pid1 = fork();
    if (pid1 == 0)
    {
        //In child process
        sleep(5);
        printf("Finished child process %d\r\n",getpid());
    }
    else {
    pid2=fork();
    if (pid2 == 0)
    {
        sleep(1);
        printf("Finished child process %d\r\n",getpid());
    }
    }
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);
}