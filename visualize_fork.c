#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
    int pid = fork();
    int n;
    if (pid == 0)
    {
        n = 0;
    }
    else {
        n = 6;
    }

    if (pid != 0)
    {
        wait(NULL);
    }

    int i;
    for (i = n; i < n +5;i++)
    {
        printf("%d\r\n",i);
        fflush(stdout);
    }

    return 0;
}