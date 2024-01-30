#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char * argv[])
{
    int p1[2];
    int p2[2];

    if (pipe(p1) == -1)
    {
        printf("Error creating the pipe p1\r\n");
    }

    if (pipe(p2) == -1)
    {
        printf("Error creating the pipe p2\r\n");
    }

    int pid = fork();
    if (pid == 0)
    {
        /*Child process*/
        /*Closing pipe ends that are not used*/
        close(p1[0]);
        close(p2[1]);
        int x = 8;
        printf("Writing to p1\r\n");
        write(p1[1],&x,sizeof(int));
        printf("Written %d to p1\r\n",x);
        int readValue;
        printf("Reading from p2\r\n");
        read(p2[0],&readValue,sizeof(int));
        printf("Read value from p2\r\n");
        close(p1[1]);
        close(p2[0]);
    }
    else {
        /*Parent process*/
        close(p1[1]);
        close(p2[0]);
        int readValue;
        printf("Reading from p1\r\n");
        read(p1[0],&readValue,sizeof(int));
        printf("Read value %d from p1\r\n",readValue);
        printf("Writing to p2\r\n");
        int valMul = readValue*5;
        write(p2[1],&valMul,sizeof(valMul));
        printf("Written value %d to p2\r\n",valMul);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }


    return 0;
}