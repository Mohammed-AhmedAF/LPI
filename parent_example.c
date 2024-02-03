#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>


int main(int argc, char * argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        printf("This is the child process, parent is %d\r\n",getppid());
        sleep(5);
        //The parent process becomes systemd, init replacement
        printf("This is the child process, parent is %d\r\n",getppid());
    }
    else
    {
        sleep(1);
        exit(0);
    }
}