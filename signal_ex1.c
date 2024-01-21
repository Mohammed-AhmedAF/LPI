#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
    int pid;
    pid = fork();
    if (pid == -1)
    {
        return 1;
    }
    else
    {
        if (pid == 0) 
        {
            for (int i = 0; i < 1000;i++)
            {
                printf("We are in the child process.\r\n");
                usleep(50000);
            }
        }
        else {
            sleep(1);
            kill(pid,SIGKILL);
            printf("We are in the parent process\r\n");
        }
    }
}
