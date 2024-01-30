#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
    int fd = open("fifo2",O_RDONLY);

    if (fd == -1)
    {
        printf("Error opening file.\r\n");
    }
    else
    {
        char readChar;
        for (int i = 0; i < 5; i++)
        {
            read(fd,&readChar,sizeof(char));
            printf("Character read: %c\r\n",readChar);
        }
        printf("Finished reading file\r\n");
        printf("Closing FIFO file\r\n");
        close(fd);
        printf("Closed FIFO file\r\n");
    }

    return 0;
}
