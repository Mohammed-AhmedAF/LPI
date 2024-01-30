#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char * argv[])
{
    //Create a FIFO
    int ret = 0;
    ret = mkfifo("fifo1",0777);
    if (ret == -1)
    {
        printf("Error creating FIFO\r\n");
    }

    printf("Opening FIFO.\r\n");
    //With FIFO, open will hang until the FIFO is read
    int fd = open("fifo1",O_WRONLY);
    if (fd == -1)
    {
        printf("Error opening file.\r\n");
    }

    char x[15] = "Hello World\r\n\0";
    write(fd,&x,sizeof(x));
    close(fd);



    return 0;

}