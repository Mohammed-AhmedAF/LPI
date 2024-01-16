#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

int main()
{
    int sz;
    char bfr[100];
    char read_bfr[100];
    strcpy(bfr,"I am written to the fille!! YAY!!\n");

    int fd = open("file1.txt",O_RDWR |O_APPEND);
    if (fd < 0)
    {
        perror("There was an error while opening the file.");
        exit(1);
    }

    sz = write(fd,bfr,strlen(bfr));
    printf("The number of lines written to the buffer is %d\n",sz);

    //Reopen for reading
    fd = open("file1.txt",O_RDONLY);

    sz = read(fd,read_bfr,50);

    printf("%s\n",read_bfr);

    close(fd);
    return 0;
}