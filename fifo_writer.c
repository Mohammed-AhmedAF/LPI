#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("fifo2",O_WRONLY);
    if (fd == -1)
    {
        printf("Error opening file.\r\n");
    }
    else {
        char arr [5] = {'a','b','c','d','e'};
        for (int i = 0; i < 5; i++)
        {
            write(fd,&arr[i],sizeof(char));
            printf("Wrote %c\r\n",arr[i]);
        }

        /*Closing file*/
        printf("Closing file.\r\n");
        close(fd);
        printf("FIFO closed.\r\n");
        }

    return 0;
}