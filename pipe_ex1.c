#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int fd[2];
    int pid;
    if (pipe(fd)  == -1)
    {
        printf("Error creating pipe.");
    }

    pid = fork();
    if (pid == 0)
    {
        //closing the read end of the pipe
        close(fd[0]);
        int y = 4;
        write(fd[1],&y,sizeof(int));
        close(fd[1]);
    }
    else
    {
        //Closing the write end of the pipe
        close(fd[1]);
        int readValue;
        read(fd[0],&readValue,sizeof(int));
        close(fd[0]);
        printf("Value read is %d\r\n.",readValue);
    }


    return 0;
}