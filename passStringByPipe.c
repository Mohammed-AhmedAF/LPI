#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int agrc, char * argv [])
{
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid < 0)
    {
        return 2;
    }
    if (pid == 0)
    {
        /*Closing read side of the pipe*/
        /*Child process*/
        close(fd[0]);
        char str[200];
        printf("Input string: ");
        fgets(str,200,stdin);

        str[strlen(str)-1] = '\0';

        int n = strlen(str)+1;
        //Wrting the number of characters
        if (write(fd[1],&n,sizeof(int)) < 0)
        {
            return 3;
        }

        //Writing the characters of the string
        if (write(fd[1],str,sizeof(char)*n) < 0)
        {
            return 3;
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char str[200];
        int n;
        if (read(fd[0],&n,sizeof(int)) < 0)
        {
            return 3;
        }
        if (read(fd[0],str,n) < 0)
        {
            return 3;
        }

        printf("In parent process %d, received string is %s\r\n",getpid(),str);
        close(fd[0]);
    }
}
