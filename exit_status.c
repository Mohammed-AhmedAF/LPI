#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        int ret = execlp("ping","ping","-c","1","google.con",NULL);
        return ret;
    }
    else
    {
        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus))
        {
            int exitcode = WEXITSTATUS(wstatus);
            if (exitcode == 0)
            {
                printf("Success!\r\n");
            }
            else
            {
                printf("Failure!\r\n");
            }
        }
    }

    return 0;
}